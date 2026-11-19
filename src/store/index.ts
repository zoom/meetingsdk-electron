import { defineStore } from 'pinia'
import { ref } from 'vue'

export const useAppStore = defineStore('app', () => {
  // State
  const zoomAuth = ref<any>({})
  const zoomMeeting = ref<any>({})

  // Actions
  function setZoomAuth(auth: any) {
    zoomAuth.value = auth
  }

  function setZoomMeeting(meeting: any) {
    zoomMeeting.value = meeting
  }

  return {
    // State
    zoomAuth,
    zoomMeeting,
    // Actions
    setZoomAuth,
    setZoomMeeting
  }
})
