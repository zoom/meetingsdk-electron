<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="setMeetingStatisticsWarningNotificationCB">SetMeetingStatisticsWarningNotificationCB</el-button>
    <el-button type="primary" round plain @click="setMeetingParameterNotificationCB">SetMeetingParameterNotificationCB</el-button>
    <el-button type="primary" round plain @click="setOnMeetingTopicChangedCB">SetOnMeetingTopicChangedCB</el-button>
    <el-button type="primary" round plain @click="setOnMeetingFullToWatchLiveStreamCB">SetOnMeetingFullToWatchLiveStreamCB</el-button>
    <el-button type="primary" round plain @click="setOnUserNetworkStatusChangedCB">SetOnUserNetworkStatusChangedCB</el-button>
    <el-button type="primary" round plain @click="setOnAppSignalPanelUpdatedCB">SetOnAppSignalPanelUpdatedCB</el-button>
    <el-button type="primary" round plain @click="leaveMeeting">LeaveMeeting</el-button>
    <el-button type="primary" round plain @click="lockMeeting">Lock_Meeting</el-button>
    <el-button type="primary" round plain @click="unLockMeeting">Un_lock_Meeting</el-button>
    <el-button type="primary" round plain @click="getSharingConnQuality">GetSharingConnQuality</el-button>
    <el-button type="primary" round plain @click="getVideoConnQuality">GetVideoConnQuality</el-button>
    <el-button type="primary" round plain @click="getAudioConnQuality">GetAudioConnQuality</el-button>
    <el-button type="primary" round plain @click="getMeetingAudioStatisticInfo">GetMeetingAudioStatisticInfo</el-button>
    <el-button type="primary" round plain @click="getMeetingVideoStatisticInfo">GetMeetingVideoStatisticInfo</el-button>
    <el-button type="primary" round plain @click="getMeetingShareStatisticInfo">GetMeetingShareStatisticInfo</el-button>
    <div class="in-line">
      <el-button type="primary" round plain @click="canSetMeetingTopic">CanSetMeetingTopic</el-button>
      <el-input v-model.trim="meetingTopic" placeholder="input topic" @keyup.enter.native="setMeetingTopic" />
      <el-button type="primary" round plain @click="setMeetingTopic">SetMeetingTopic</el-button>
    </div>
  </div>
  <div class="result">Result: {{result}}</div>
  <div class="result"> 
    <div class="result-item"> 
      <span class="title">meetingstatuscb <el-button size="small" @click="meetingstatuscb_options=[]">Clear</el-button></span>
      <div class="callback-list">
        <span v-for="(item, index) in meetingstatuscb_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">onMeetingStatisticsWarningNotification <el-button size="small" @click="onMeetingStatisticsWarningNotification_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in onMeetingStatisticsWarningNotification_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">onMeetingParameterNotification <el-button size="small" @click="onMeetingParameterNotification_options=[]">Clear</el-button></span>
      <div class="callback-list">
        <span v-for="(item, index) in onMeetingParameterNotification_options" :key="index">{{index}} : {{item}}</span>
      </div> 
    </div>
    <div class="result-item"> 
      <span class="title">onMeetingTopicChanged <el-button size="small" @click="onMeetingTopicChanged_options=[]">Clear</el-button></span>
      <div class="callback-list">
        <span v-for="(item, index) in onMeetingTopicChanged_options" :key="index">{{index}} : {{item}}</span>
      </div> 
    </div>
    <div class="result-item"> 
      <span class="title">onMeetingFullToWatchLiveStream <el-button size="small" @click="onMeetingFullToWatchLiveStream_options=[]">Clear</el-button></span>
      <div class="callback-list">
        <span v-for="(item, index) in onMeetingFullToWatchLiveStream_options" :key="index">{{index}} : {{item}}</span>
      </div> 
    </div>
    <div class="result-item"> 
      <span class="title">onUserNetworkStatusChanged <el-button size="small" @click="onUserNetworkStatusChanged_options=[]">Clear</el-button></span>
      <div class="callback-list">
        <span v-for="(item, index) in onUserNetworkStatusChanged_options" :key="index">{{index}} : {{item}}</span>
      </div> 
    </div>
    <div class="result-item"> 
      <span class="title">onAppSignalPanelUpdated <el-button size="small" @click="onAppSignalPanelUpdated_value=0">Clear</el-button></span>
      <span v-if="onAppSignalPanelUpdated_value">updated {{onAppSignalPanelUpdated_value}}</span>
      <div>
        <el-button type="primary" size="small" round plain @click="canShowPanel">CanShowPanel</el-button>
        <el-input size="small" v-model.trim="showPanelParams.x" placeholder="input x" />
        <el-input size="small" v-model.trim="showPanelParams.y" placeholder="input y" />
        <el-select size="small" v-model="showPanelParams.windowID" placeholder="select windowID">
          <el-option v-for="(item, index) in windowIdList" :key="index" :label="item.label" :value="item.value"></el-option>
        </el-select>
        <el-button type="primary" size="small" round plain @click="showPanel">ShowPanel</el-button>
        <el-button type="primary" size="small" round plain @click="hidePanel">HidePanel</el-button>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, reactive, onBeforeMount, onMounted, onBeforeUnmount } from 'vue'
import { ZoomMeetingStatus, StatisticsWarningType } from '../../../lib/settings.js'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const desktopCapturer = remote.desktopCapturer
const result = ref()
const meetingstatuscb_options = ref<any[]>([])
const onMeetingStatisticsWarningNotification_options = ref<any[]>([])
const onMeetingParameterNotification_options = ref<any[]>([])
const onMeetingTopicChanged_options = ref<string[]>([])
const onMeetingFullToWatchLiveStream_options = ref<string[]>([])
const onUserNetworkStatusChanged_options = ref<string[]>([])
const onAppSignalPanelUpdated_value = ref<number>(0)

const meetingstatuscb = (meetingStatus: string, result: string) => {
  let statusContent = Object.keys(ZoomMeetingStatus).find(k => ZoomMeetingStatus[k] == meetingStatus)
  console.log('meetingstatuscb', meetingStatus, result, statusContent)
  meetingstatuscb_options.value.push(statusContent)
}
const onMeetingStatisticsWarningNotification = (type: number) => {
  let content = Object.keys(StatisticsWarningType).find(k => StatisticsWarningType[k] == type)
  console.log('onMeetingStatisticsWarningNotification', type, content)
  onMeetingStatisticsWarningNotification_options.value.push(content)
}
const onMeetingParameterNotification = (meeting_param: any) => {
  console.log('onMeetingParameterNotification', meeting_param)
  meeting_param.meeting_number = meeting_param.meeting_number + ''
  let content = JSON.stringify(meeting_param)
  onMeetingParameterNotification_options.value.push(content)
}
const onMeetingTopicChanged = (sTopic: string) => {
  console.log('onMeetingTopicChanged', sTopic)
  onMeetingTopicChanged_options.value.push(`sTopic: ${sTopic}`)
}
const onMeetingFullToWatchLiveStream = (sLiveStreamUrl: string) => {
  console.log('onMeetingFullToWatchLiveStream', sLiveStreamUrl)
  onMeetingFullToWatchLiveStream_options.value.push(`sLiveStreamUrl: ${sLiveStreamUrl}`)
}
const onUserNetworkStatusChanged = (type: number, level: number, userId: number, uplink: boolean) => {
  console.log('onUserNetworkStatusChanged', type, level, userId, uplink)
  onUserNetworkStatusChanged_options.value.push(`type: ${type} level: ${level} userId: ${userId} uplink: ${uplink}`)
}
const onAppSignalPanelUpdated = () => {
  console.log('onAppSignalPanelUpdated')
  onAppSignalPanelUpdated_value.value++
}
const zoomMeeting = remote.app.zoomSdkModule.Meeting

const setMeetingStatusCB = () => {
  let ret = zoomMeeting.SetMeetingStatusCB(meetingstatuscb)
  result.value = getSDKResult('SetMeetingStatusCB', ret)
}

const setMeetingStatisticsWarningNotificationCB = () => {
  let ret = zoomMeeting.SetMeetingStatisticsWarningNotificationCB(onMeetingStatisticsWarningNotification)
  result.value = getSDKResult('SetMeetingStatisticsWarningNotificationCB', ret)
}

const setMeetingParameterNotificationCB = () => {
  let ret = zoomMeeting.SetMeetingParameterNotificationCB(onMeetingParameterNotification)
  result.value = getSDKResult('SetMeetingParameterNotificationCB', ret)
}

const setOnMeetingTopicChangedCB = () => {
  let ret = zoomMeeting.SetOnMeetingTopicChangedCB(onMeetingTopicChanged)
  result.value = getSDKResult('SetOnMeetingTopicChangedCB', ret)
}

const setOnMeetingFullToWatchLiveStreamCB = () => {
  let ret = zoomMeeting.SetOnMeetingFullToWatchLiveStreamCB(onMeetingFullToWatchLiveStream)
  result.value = getSDKResult('SetOnMeetingFullToWatchLiveStreamCB', ret)
}

const setOnUserNetworkStatusChangedCB = () => {
  let ret = zoomMeeting.SetOnUserNetworkStatusChangedCB(onUserNetworkStatusChanged)
  result.value = getSDKResult('SetOnUserNetworkStatusChangedCB', ret)
}

const setOnAppSignalPanelUpdatedCB = () => {
  let ret = zoomMeeting.SetOnAppSignalPanelUpdatedCB(onAppSignalPanelUpdated)
  result.value = getSDKResult('SetOnAppSignalPanelUpdatedCB', ret)
}

const leaveMeeting = () => {
  let ret = zoomMeeting.LeaveMeeting()
  result.value = getSDKResult('LeaveMeeting', ret)
}

const lockMeeting = () => {
  let ret = zoomMeeting.Lock_Meeting()
  result.value = getSDKResult('Lock_Meeting', ret)
}

const unLockMeeting = () => {
  let ret = zoomMeeting.Un_lock_Meeting()
  result.value = getSDKResult('Un_lock_Meeting', ret)
}

const getSharingConnQuality = () => {
  let ret = zoomMeeting.GetSharingConnQuality()
  result.value = `GetSharingConnQuality - ${ret}`
}

const getVideoConnQuality = () => {
  let ret = zoomMeeting.GetVideoConnQuality()
  result.value = `GetVideoConnQuality - ${ret}`
}

const getAudioConnQuality = () => {
  let ret = zoomMeeting.GetAudioConnQuality()
  result.value = `GetAudioConnQuality - ${ret}`
}

const getMeetingAudioStatisticInfo = () => {
  let ret = zoomMeeting.GetMeetingAudioStatisticInfo()
  result.value = `GetMeetingAudioStatisticInfo - ${JSON.stringify(ret)}`
}

const getMeetingVideoStatisticInfo = () => {
  let ret = zoomMeeting.GetMeetingVideoStatisticInfo()
  result.value = `GetMeetingVideoStatisticInfo - ${JSON.stringify(ret)}`
}

const getMeetingShareStatisticInfo = () => {
  let ret = zoomMeeting.GetMeetingShareStatisticInfo()
  result.value = `GetMeetingShareStatisticInfo - ${JSON.stringify(ret)}`
}

const canSetMeetingTopic = () => {
  let ret = zoomMeeting.CanSetMeetingTopic()
  result.value = `CanSetMeetingTopic - ${ret}`
}

const meetingTopic = ref('')
const setMeetingTopic = () => {
  let param = {
    sTopic: meetingTopic.value
  }
  let ret = zoomMeeting.SetMeetingTopic(param)
  result.value = getSDKResult('SetMeetingTopic', ret, param)
}

const canShowPanel = () => {
  let ret = zoomMeeting.CanShowPanel()
  result.value = `CanShowPanel - ${ret}`
}

const showPanelParams = reactive({
  x: 100,
  y: 100,
  windowID: 0
})
const showPanel = () => {
  let ret = zoomMeeting.ShowPanel(showPanelParams)
  result.value = getSDKResult('ShowPanel', ret, showPanelParams)
}

const hidePanel = () => {
  let ret = zoomMeeting.HidePanel()
  result.value = getSDKResult('HidePanel', ret)
}

const handleMsg = (event: any) => {
  if (event.type == 'message') {
    let { meetingStatus, result } = event.data
    if (Number.isInteger(meetingStatus) || Number.isInteger(result)) {
      meetingstatuscb(meetingStatus, result)
    }
  }
}

const windowIdList = ref<any[]>([])
onBeforeMount(() => {
  desktopCapturer.getSources({ types: ['window'] }).then((sources: any) => {
    let tempList = []
    console.log(sources)
    for (let index in sources) {
      const obj = { ...sources[index] }
      const id = obj.id.split(':')[1]
      tempList.push({value: parseInt(id), label: obj.name})
    }
    windowIdList.value = tempList
    showPanelParams.windowID = tempList.length > 0 ? tempList[0].value : 0
  })
})

onMounted(() => {
  setMeetingStatisticsWarningNotificationCB()
  setMeetingParameterNotificationCB()
  setOnMeetingTopicChangedCB()
  setOnAppSignalPanelUpdatedCB()
  window.addEventListener('message', msg => handleMsg(msg))
})

onBeforeUnmount(() => {
  window.removeEventListener('message', handleMsg)
})
</script>

<style scoped lang="scss">
.result {
  .title {
    width: 310px;
  }
  .el-input {
    width: 90px !important;
  }
  .el-select {
    width: 160px;
  }
}
</style>