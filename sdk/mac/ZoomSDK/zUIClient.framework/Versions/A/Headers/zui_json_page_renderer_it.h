#ifndef ZUI_JSON_PAGE_RENDERER_IT_H
#define ZUI_JSON_PAGE_RENDERER_IT_H

#if defined(__MACOS__)

#include <memory>
#include <string>

#import <zUI/view.h>
#import <zUIClient/zUI_stdafx.h>

// Receives actions emitted by button nodes. The renderer does not interpret
// action names or initiate network activity. Call SetSink(nullptr) before the
// sink is destroyed.
class ZUIClient_API IZUIJsonPageRendererSink {
public:
  virtual ~IZUIJsonPageRendererSink() = default;
  virtual void OnJsonPageAction(const std::string& action) = 0;
};

// Renders a validated server-provided JSON page into an embeddable ZUI View.
// All methods must be called on the ZUI/UI thread. The caller owns fetching,
// caching, authentication, and retry; this interface only consumes JSON.
class ZUIClient_API IZUIJsonPageRenderer {
public:
  virtual ~IZUIJsonPageRenderer() = default;

  virtual void SetSink(IZUIJsonPageRendererSink* sink) = 0;

  // Replaces the current page only after parsing and schema validation pass.
  // Returns false and leaves the previously rendered page intact on failure.
  virtual bool SetPageJson(const std::string& json, std::string* error) = 0;

  // The returned View can be embedded in any ZUI host. Views obtained before
  // a subsequent successful SetPageJson call update reactively.
  virtual std::shared_ptr<zui::View> GetView() = 0;

  virtual void Clear() = 0;
};

#endif  // defined(__MACOS__)

#endif  // ZUI_JSON_PAGE_RENDERER_IT_H
