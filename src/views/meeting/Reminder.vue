<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="setOnReminderNotifyCB">SetOnReminderNotifyCB</el-button>
    <div class="in-line">
      <el-input-number v-model="config_left" :min="0" />
      <el-input-number v-model="config_top" :min="0" />
      <el-select v-model="config_parentWindowHandle" placeholder="Select">
        <el-option v-for="(item, index) in appsList" :key="index" :label="item.label" :value="item.value"></el-option>
      </el-select>
      <el-input v-model.trim="config_parentWindowHandle" placeholder="parent window handle (Win)" />
      <el-input v-model.trim="config_backgroundColor" placeholder="backgroundColor" />
      <el-button type="primary" round plain @click="setMultiReminderDisclaimerUIConfig">SetMultiReminderDisclaimerUIConfig</el-button>
    </div>
    <el-button type="primary" round plain @click="updateMultiReminderDisclaimerUI">UpdateMultiReminderDisclaimerUI</el-button>
  </div>
  <div class="result">Result: {{result}}</div>
  <div class="result">
    <div class="result-item">
      <span class="title">onReminderNotify <el-button size="small" @click="onReminderNotify_options=[]">Clear</el-button></span>
      <el-button type="primary" size="small" round plain @click="ignore">Ignore</el-button>
      <el-button type="primary" size="small" round plain @click="accept">Accept</el-button>
      <el-button type="primary" size="small" round plain @click="decline">Decline</el-button>
      <el-button type="primary" size="small" round plain @click="setHideFeatureDisclaimers">SetHideFeatureDisclaimers</el-button>
      <div class="callback-list">
        <span v-for="(item, index) in onReminderNotify_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const desktopCapturer = remote.desktopCapturer
const result = ref()
const onReminderNotify_options = ref<any[]>([])

const onReminderNotify = (content: any) => {
  console.log('onReminderNotify', content)
  onReminderNotify_options.value.push(JSON.stringify(content))
}

const zoomMeetingReminder = remote.app.zoomSdkModule.Meeting.GetMeetingReminder({onReminderNotify})

const setOnReminderNotifyCB = () => {
  let ret = zoomMeetingReminder.SetOnReminderNotifyCB(onReminderNotify)
  result.value = getSDKResult('SetOnReminderNotifyCB', ret)
}
const ignore = () => {
  let ret = zoomMeetingReminder.Ignore()
  result.value = getSDKResult('Ignore', ret)
}
const accept = () => {
  let ret = zoomMeetingReminder.Accept()
  result.value = getSDKResult('Accept', ret)
}
const decline = () => {
  let ret = zoomMeetingReminder.Decline()
  result.value = getSDKResult('Decline', ret)
}
const setHideFeatureDisclaimers = () => {
  let ret = zoomMeetingReminder.SetHideFeatureDisclaimers()
  result.value = getSDKResult('SetHideFeatureDisclaimers', ret)
}
const config_left = ref(0)
const config_top = ref(0)
const config_parentWindowHandle = ref('')
const config_backgroundColor = ref('0xffffff')
const appsList = ref<any[]>([])
const setMultiReminderDisclaimerUIConfig = () => {
  let n = parseInt(config_backgroundColor.value, 16)
  let param = {
    left: config_left.value,
    top: config_top.value,
    parentWindowHandle: config_parentWindowHandle.value,
    backgroundColor: Number.isFinite(n) ? n : 0xffffff
  }
  let ret = zoomMeetingReminder.SetMultiReminderDisclaimerUIConfig(param)
  result.value = getSDKResult('SetMultiReminderDisclaimerUIConfig', ret, param)
}
const updateMultiReminderDisclaimerUI = () => {
  let ret = zoomMeetingReminder.UpdateMultiReminderDisclaimerUI()
  result.value = getSDKResult('UpdateMultiReminderDisclaimerUI', ret)
}

onMounted(() => {
  desktopCapturer.getSources({ types: ['window'] }).then((sources: any) => {
    for (let i in sources) {
      let obj = {...sources[i]}
      let parentWindowHandle = obj.id.split(':')[1]
      if (window.navigator.userAgent.indexOf('Windows') > -1) {
        parentWindowHandle = Number(obj.id.split(':')[1]).toString(16)
      }
      appsList.value.push({value: parentWindowHandle, label: obj.name})
    }
  })
})
</script>

<style scoped lang="scss">
.result {
  .title {
    width: 230px;
  }
}
</style>
