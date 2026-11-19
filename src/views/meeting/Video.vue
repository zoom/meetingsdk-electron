<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="setMeetingVideoStatusCB">SetMeetingVideoStatusCB</el-button>
    <el-button type="primary" round plain @click="setActiveSpeakerVideoUserChangedCB">SetActiveSpeakerVideoUserChangedCB</el-button>
    <el-button type="primary" round plain @click="setActiveVideoUserChangedCB">SetActiveVideoUserChangedCB</el-button>
    <el-button type="primary" round plain @click="setSpotlightedUserListChangeNotificationCB">SetSpotlightedUserListChangeNotificationCB</el-button>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="muteVideo">MuteVideo</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="unMuteVideo">UnMuteVideo</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="pinToFirstView_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="canPinToFirstView">CanPinToFirstView</el-button>
      <el-button type="primary" round plain @click="pinVideoToFirstView">PinVideoToFirstView</el-button>
      <el-button type="primary" round plain @click="unPinVideoFromFirstView">UnPinVideoFromFirstView</el-button>
      <el-button type="primary" round plain @click="unPinAllVideosFromFirstView">UnPinAllVideosFromFirstView</el-button>
      <el-button type="primary" round plain @click="getPinnedUserListFromFirstView">GetPinnedUserListFromFirstView</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="pinToSecondView_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="canPinToSecondView">CanPinToSecondView</el-button>
      <el-button type="primary" round plain @click="pinVideoToSecondView">PinVideoToSecondView</el-button>
      <el-button type="primary" round plain @click="unPinVideoFromSecondView">UnPinVideoFromSecondView</el-button>
      <el-button type="primary" round plain @click="getPinnedUserListFromSecondView">GetPinnedUserListFromSecondView</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="spotlight_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="canSpotlight">CanSpotlight</el-button>
      <el-button type="primary" round plain @click="spotlightVideo">SpotlightVideo</el-button>
      <el-button type="primary" round plain @click="canUnSpotlight">CanUnSpotlight</el-button>
      <el-button type="primary" round plain @click="unSpotlightVideo">UnSpotlightVideo</el-button>
    </div>
    <el-button type="primary" round plain @click="unSpotlightAllVideos">UnSpotlightAllVideos</el-button>
    <el-button type="primary" round plain @click="getSpotlightedUserList">GetSpotlightedUserList</el-button>
    <el-button type="primary" round plain @click="getLocalVideoOrderList">GetLocalVideoOrderList</el-button>
    <el-button type="primary" round plain @click="getVideoOrderList">GetVideoOrderList</el-button>
    <el-button type="primary" round plain @click="isSupportFollowHostVideoOrder">IsSupportFollowHostVideoOrder</el-button>
    <el-button type="primary" round plain @click="isFollowHostVideoOrderOn">IsFollowHostVideoOrderOn</el-button>
    <el-checkbox v-model="followHostVideoOrder" label="EnableFollowHostVideoOrder" @change="enableFollowHostVideoOrder"></el-checkbox>
    <el-checkbox v-model="hide" label="HideOrShowNoVideoUserOnVideoWall" @change="hideOrShowNoVideoUserOnVideoWall"></el-checkbox>
    <div class="in-line">
      <el-select v-model="videoPreference_mode" placeholder="Select">
        <el-option v-for="(item, key) in SDKVideoPreferenceMode" :key="item" :label="key" :value="item"></el-option>
      </el-select>
      <el-input-number v-model="minimumFrameRate" :min="0" :max="30" />
      <el-input-number v-model="maximumFrameRate" :min="0" :max="30" />
      <el-button type="primary" round plain @click="setVideoQualityPreference">SetVideoQualityPreference</el-button>
    </div>
  </div>
  <div class="result">Result: {{result}}</div>
  <div class="result"> 
    <div class="result-item"> 
      <span class="title">onUserVideoStatusChange <el-button size="small" @click="onUserVideoStatusChange_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in onUserVideoStatusChange_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">onActiveSpeakerVideoUserChanged <el-button size="small" @click="onActiveSpeakerVideoUserChanged_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in onActiveSpeakerVideoUserChanged_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">onActiveVideoUserChanged <el-button size="small" @click="onActiveVideoUserChanged_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in onActiveVideoUserChanged_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item">
      <span class="title">onSpotlightedUserListChangeNotification <el-button size="small" @click="onSpotlightedUserListChangeNotification_options=[]">Clear</el-button></span>
      <div class="callback-list">
        <span v-for="(item, index) in onSpotlightedUserListChangeNotification_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue'
import { VideoStatus, SDKVideoPreferenceMode, PinResult, SpotlightResult } from '../../../lib/settings.js'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const result = ref()
const onUserVideoStatusChange_options = ref<any[]>([])
const onActiveSpeakerVideoUserChanged_options = ref<any[]>([])
const onActiveVideoUserChanged_options = ref<any[]>([])
const onSpotlightedUserListChangeNotification_options = ref<any[]>([])

const onUserVideoStatusChange = (status: any) => {
  console.log('onUserVideoStatusChange', status)
  let content = `${status.userId} - ${Object.keys(VideoStatus).find(k => VideoStatus[k] == status.videoStatus)}`
  onUserVideoStatusChange_options.value.push(content)
}
const onActiveSpeakerVideoUserChanged = (userId: number) => {
  console.log('onActiveSpeakerVideoUserChanged', userId)
  onActiveSpeakerVideoUserChanged_options.value.push(userId)
}
const onActiveVideoUserChanged = (userId: number) => {
  console.log('onActiveVideoUserChanged', userId)
  onActiveVideoUserChanged_options.value.push(userId)
}
const onSpotlightedUserListChangeNotification = (lstSpotlightedUserID: any) => {
  onSpotlightedUserListChangeNotification_options.value.push(lstSpotlightedUserID)
}
const zoomMeetingVideo = remote.app.zoomSdkModule.Meeting.GetMeetingVideo({onUserVideoStatusChange, onActiveSpeakerVideoUserChanged, onActiveVideoUserChanged, onSpotlightedUserListChangeNotification})
const zoomMeetingParticipants = remote.app.zoomSdkModule.Meeting.GetMeetingParticipantsCtrl()
const participantsList = ref<any[]>([])
const participants_value = ref()
const pinToFirstView_value = ref()
const pinToSecondView_value = ref()
const spotlight_value = ref()
const hide = ref(true)
const followHostVideoOrder = ref(false)

const setMeetingVideoStatusCB = () => {
  let ret = zoomMeetingVideo.MeetingVideo_SetMeetingVideoStatusCB(onUserVideoStatusChange)
  result.value = getSDKResult('MeetingVideo_SetMeetingVideoStatusCB', ret)
}

const setActiveSpeakerVideoUserChangedCB = () => {
  let ret = zoomMeetingVideo.MeetingVideo_SetActiveSpeakerVideoUserChangedCB(onActiveSpeakerVideoUserChanged)
  result.value = getSDKResult('MeetingVideo_SetActiveSpeakerVideoUserChangedCB', ret)
}

const setActiveVideoUserChangedCB = () => {
  let ret = zoomMeetingVideo.MeetingVideo_SetActiveVideoUserChangedCB(onActiveVideoUserChanged)
  result.value = getSDKResult('MeetingVideo_SetActiveVideoUserChangedCB', ret)
}

const setSpotlightedUserListChangeNotificationCB = () => {
  let ret = zoomMeetingVideo.MeetingVideo_SetSpotlightedUserListChangeNotificationCB(onSpotlightedUserListChangeNotification)
  result.value = getSDKResult('MeetingVideo_SetSpotlightedUserListChangeNotificationCB', ret)
}

const getParticipantsList = () => {
  let list = zoomMeetingParticipants.GetParticipantsList()
  result.value = getSDKResult('GetParticipantsList', list)
  participantsList.value = []
  let obj
  for (let item of list) {
    obj = zoomMeetingParticipants.GetUserInfoByUserID(item.userid)
    participantsList.value.push(obj)
  }
  if (participantsList.value.length == 0) {
    participants_value.value = ''
    pinToFirstView_value.value = ''
    pinToSecondView_value.value = ''
    spotlight_value.value = ''
  } else {
    if (!participants_value.value) {
      participants_value.value = obj.userID
    }
    if (!pinToFirstView_value.value) {
      pinToFirstView_value.value = obj.userID
    }
    if (!pinToSecondView_value.value) {
      pinToSecondView_value.value = obj.userID
    }
    if (!spotlight_value.value) {
      spotlight_value.value = obj.userID
    }
  }
}

const muteVideo = () => {
  let param = {userid: participants_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_MuteVideo(param)
  result.value = getSDKResult('MeetingVideo_MuteVideo', ret, param)
}

const unMuteVideo = () => {
  let param = {userid: participants_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_UnMuteVideo(param)
  result.value = getSDKResult('MeetingVideo_UnMuteVideo', ret, param)
}

const pinVideoToFirstView = () => {
  let param = {userid: pinToFirstView_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_PinVideoToFirstView(param)
  result.value = getSDKResult('MeetingVideo_PinVideoToFirstView', ret, param)
}

const canPinToFirstView = () => {
  let param = {userid: pinToFirstView_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_CanPinToFirstView(param)
  let resultName = Object.keys(PinResult).find(k => PinResult[k] == ret?.result)
  result.value = getSDKResult('MeetingVideo_CanPinToFirstView', ret, param, false) + (resultName ? ` ${resultName}` : '')
}

const pinVideoToSecondView = () => {
  let param = {userid: pinToSecondView_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_PinVideoToSecondView(param)
  result.value = getSDKResult('MeetingVideo_PinVideoToSecondView', ret, param)
}

const canPinToSecondView = () => {
  let param = {userid: pinToSecondView_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_CanPinToSecondView(param)
  let resultName = Object.keys(PinResult).find(k => PinResult[k] == ret?.result)
  result.value = getSDKResult('MeetingVideo_CanPinToSecondView', ret, param, false) + (resultName ? ` ${resultName}` : '')
}

const unPinVideoFromFirstView = () => {
  let param = {userid: pinToFirstView_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_UnPinVideoFromFirstView(param)
  result.value = getSDKResult('MeetingVideo_UnPinVideoFromFirstView', ret, param)
}

const unPinVideoFromSecondView = () => {
  let param = {userid: pinToSecondView_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_UnPinVideoFromSecondView(param)
  result.value = getSDKResult('MeetingVideo_UnPinVideoFromSecondView', ret, param)
}

const unPinAllVideosFromFirstView = () => {
  let ret = zoomMeetingVideo.MeetingVideo_UnPinAllVideosFromFirstView()
  result.value = getSDKResult('MeetingVideo_UnPinAllVideosFromFirstView', ret)
}

const getPinnedUserListFromFirstView = () => {
  let ret = zoomMeetingVideo.MeetingVideo_GetPinnedUserListFromFirstView()
  result.value = getSDKResult('MeetingVideo_GetPinnedUserListFromFirstView', ret, null, false)
}

const getPinnedUserListFromSecondView = () => {
  let ret = zoomMeetingVideo.MeetingVideo_GetPinnedUserListFromSecondView()
  result.value = getSDKResult('MeetingVideo_GetPinnedUserListFromSecondView', ret, null, false)
}

const getLocalVideoOrderList = () => {
  let ret = zoomMeetingVideo.MeetingVideo_GetLocalVideoOrderList()
  result.value = getSDKResult('MeetingVideo_GetLocalVideoOrderList', ret, null, false)
}

const spotlightVideo = () => {
  let param = {userid: spotlight_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_SpotlightVideo(param)
  result.value = getSDKResult('MeetingVideo_SpotlightVideo', ret, param)
}

const canSpotlight = () => {
  let param = {userid: spotlight_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_CanSpotlight(param)
  let resultName = Object.keys(SpotlightResult).find(k => SpotlightResult[k] == ret?.result)
  result.value = getSDKResult('MeetingVideo_CanSpotlight', ret, param, false) + (resultName ? ` ${resultName}` : '')
}

const canUnSpotlight = () => {
  let param = {userid: spotlight_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_CanUnSpotlight(param)
  let resultName = Object.keys(SpotlightResult).find(k => SpotlightResult[k] == ret?.result)
  result.value = getSDKResult('MeetingVideo_CanUnSpotlight', ret, param, false) + (resultName ? ` ${resultName}` : '')
}

const unSpotlightVideo = () => {
  let param = {userid: spotlight_value.value}
  let ret = zoomMeetingVideo.MeetingVideo_UnSpotlightVideo(param)
  result.value = getSDKResult('MeetingVideo_UnSpotlightVideo', ret, param)
}

const unSpotlightAllVideos = () => {
  let ret = zoomMeetingVideo.MeetingVideo_UnSpotlightAllVideos()
  result.value = getSDKResult('MeetingVideo_UnSpotlightAllVideos', ret)
}

const getSpotlightedUserList = () => {
  let ret = zoomMeetingVideo.MeetingVideo_GetSpotlightedUserList()
  result.value = getSDKResult('MeetingVideo_GetSpotlightedUserList', ret, null, false)
}

const getVideoOrderList = () => {
  let ret = zoomMeetingVideo.MeetingVideo_GetVideoOrderList()
  result.value = getSDKResult('MeetingVideo_GetVideoOrderList', ret, null, false)
}

const isSupportFollowHostVideoOrder = () => {
  let ret = zoomMeetingVideo.MeetingVideo_IsSupportFollowHostVideoOrder()
  result.value = getSDKResult('MeetingVideo_IsSupportFollowHostVideoOrder', ret, null, false)
}

const isFollowHostVideoOrderOn = () => {
  let ret = zoomMeetingVideo.MeetingVideo_IsFollowHostVideoOrderOn()
  result.value = getSDKResult('MeetingVideo_IsFollowHostVideoOrderOn', ret, null, false)
}

const enableFollowHostVideoOrder = () => {
  let param = {bEnable: followHostVideoOrder.value}
  let ret = zoomMeetingVideo.MeetingVideo_EnableFollowHostVideoOrder(param)
  result.value = getSDKResult('MeetingVideo_EnableFollowHostVideoOrder', ret, param)
}

const hideOrShowNoVideoUserOnVideoWall = () => {
  let param = {bHide: hide.value}
  let ret = zoomMeetingVideo.MeetingVideo_HideOrShowNoVideoUserOnVideoWall(param)
  result.value = getSDKResult('MeetingVideo_HideOrShowNoVideoUserOnVideoWall', ret, param)
}

const videoPreference_mode = ref(SDKVideoPreferenceMode.SDKVideoPreferenceMode_Balance)
const minimumFrameRate = ref(0)
const maximumFrameRate = ref(30)
const setVideoQualityPreference = () => {
  let param = {
    mode: videoPreference_mode.value,
    minimumFrameRate: minimumFrameRate.value,
    maximumFrameRate: maximumFrameRate.value
  }
  let ret = zoomMeetingVideo.MeetingVideo_SetVideoQualityPreference(param)
  result.value = getSDKResult('MeetingVideo_SetVideoQualityPreference', ret, param)
}

onMounted(() => {
  getParticipantsList()
})
</script>

<style scoped lang="scss">
.result {
  .title {
    width: 320px;
  }
}
</style>