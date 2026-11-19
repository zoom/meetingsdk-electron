const http = require('http')
const net = require('net')

const DEFAULT_PORT = 5173
const PORT_SCAN_LIMIT = 100

function isPortAvailable(port) {
  return new Promise((resolve) => {
    const server = net.createServer()
    server.unref()
    server.once('error', () => resolve(false))
    server.listen({ port, host: '0.0.0.0' }, () => {
      server.close(() => resolve(true))
    })
  })
}

async function resolvePort(envPort, scanLimit = PORT_SCAN_LIMIT) {
  const preferredPort = (() => {
    const port = Number.parseInt(envPort ?? '', 10)
    return Number.isFinite(port) && port > 0 && port < 65536 ? port : DEFAULT_PORT
  })()

  for (let offset = 0; offset <= scanLimit; offset++) {
    const candidate = preferredPort + offset
    if (await isPortAvailable(candidate)) {
      if (offset > 0) {
        console.log(`[electron] Using port ${candidate} instead of ${preferredPort}`)
      }
      return candidate
    }
    if (offset === 0) {
      console.log(`[electron] Port ${candidate} is in use, searching for a free port...`)
    }
  }
  throw new Error(`No available port found in range ${preferredPort}-${preferredPort + scanLimit}`)
}

function waitForHttpOk(url, opts = {}) {
  const initialWaitMs = opts.initialWaitMs ?? 2000
  const pollIntervalMs = opts.pollIntervalMs ?? 1000
  const httpTimeoutMs = opts.httpTimeoutMs ?? 5000
  const maxRetries = opts.maxRetries ?? 60

  return new Promise((resolve, reject) => {
    let retries = 0

    const attempt = () => {
      if (retries++ >= maxRetries) {
        reject(new Error(`Dev server failed to start after ${maxRetries} seconds: ${url}`))
        return
      }

      let settled = false
      const onSettled = (fn) => () => { if (!settled) fn() }

      const req = http.get(url, (res) => {
        // Consume response to avoid socket leaks.
        res.resume()
        req.destroy()

        if (res.statusCode === 200) {
          settled = true
          resolve()
        } else {
          setTimeout(onSettled(attempt), pollIntervalMs)
        }
      })

      req.setTimeout(httpTimeoutMs, () => {
        req.destroy()
        setTimeout(onSettled(attempt), pollIntervalMs)
      })

      req.on('error', () => {
        req.destroy()
        setTimeout(onSettled(attempt), pollIntervalMs)
      })
    }

    setTimeout(attempt, initialWaitMs)
  })
}

module.exports = {
  DEFAULT_PORT,
  resolvePort,
  waitForHttpOk
}

