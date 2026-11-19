const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

var ZoomMeetingVideo = (function () {
  var instance;
  /**
   * Zoom Meeting Video
   * @module zoom_meeting_video
   * @param {Function} onUserVideoStatusChange Callback event of the user video status changes.
   * @param {Function} onActiveSpeakerVideoUserChanged Callback event of the active speaker video user changes.
   * @param {Function} onActiveVideoUserChanged Callback event of the active video user changes.
   * @param {Function} onSpotlightedUserListChangeNotification Callback event for when the video spotlight user list changes.
   * @return {ZoomMeetingVideo}
   */
  function init(opts) {
    var clientOpts = opts || {};
    // Private methods and variables
    var _addon = clientOpts.addon.GetMeetingVideoCtrl();
    let _onUserVideoStatusChange = clientOpts.onUserVideoStatusChange || null;
    let _onActiveSpeakerVideoUserChanged = clientOpts.onActiveSpeakerVideoUserChanged || null;
    let _onActiveVideoUserChanged = clientOpts.onActiveVideoUserChanged || null;
    let _onSpotlightedUserListChangeNotification = clientOpts.onSpotlightedUserListChangeNotification || null;

    /**
     * Callback event of the user video status changes.
     * @event onUserVideoStatusChange
     * @param {String} userId The user ID whose video status changes
     * @param {String} status New video status {@link ZoomMeetingVideoStatus}. Video_NotReceiving means the user is still sending, but a previously received video stream is no longer available. Camera-on without a subscribed stream is On. It is not reported for the local user.
     * @note Valid for both normal user and webinar attendee.
     */
    function onUserVideoStatusChange(userId, status) {
      if (_onUserVideoStatusChange) {
        _onUserVideoStatusChange(userId, status)
      }
    }

    /**
     * Callback event of the active speaker video user changes.
     * @event onActiveSpeakerVideoUserChanged
     * @param {String} userId The ID of user who becomes the new active speaker.
     */
    function onActiveSpeakerVideoUserChanged(userId) {
      if (_onActiveSpeakerVideoUserChanged) {
        _onActiveSpeakerVideoUserChanged(userId)
      }
    }

    /**
     * Callback event of the active video user changes.
     * @event onActiveVideoUserChanged
     * @param {String} userId The ID of user who becomes the new active speaker.
     */
    function onActiveVideoUserChanged(userId) {
      if (_onActiveVideoUserChanged) {
        _onActiveVideoUserChanged(userId)
      }
    }

    /**
     * Callback event for when the video spotlight user list changes. Spotlight user means that the view will show only the specified user and won't change the view even other users speak.
     * @event onSpotlightedUserListChangeNotification
     * @param {Array} lstSpotlightedUserID spot light user list.
     */
    function onSpotlightedUserListChangeNotification(lstSpotlightedUserID) {
      if (_onSpotlightedUserListChangeNotification) {
        _onSpotlightedUserListChangeNotification(lstSpotlightedUserID)
      }
    }

    if (_addon) {
      _addon.SetMeetingVideoStatusCB(onUserVideoStatusChange);
      _addon.SetActiveSpeakerVideoUserChangedCB(onActiveSpeakerVideoUserChanged);
      _addon.SetActiveVideoUserChangedCB(onActiveVideoUserChanged);
      _addon.SetSpotlightedUserListChangeNotificationCB(onSpotlightedUserListChangeNotification);
    }

    return {
      // Public methods and variables
      /**
       * Set onUserVideoStatusChange callback.
       * @method MeetingVideo_SetMeetingVideoStatusCB
       * @param {Function} onUserVideoStatusChange
       * @return {Boolean} true or false
       */
      MeetingVideo_SetMeetingVideoStatusCB: function (onUserVideoStatusChange) {
        if (_addon && onUserVideoStatusChange && onUserVideoStatusChange instanceof Function) {
          _onUserVideoStatusChange = onUserVideoStatusChange;
          return true;
        }
        return false;
      },
      /**
       * Set onActiveSpeakerVideoUserChanged callback.
       * @method MeetingVideo_SetActiveSpeakerVideoUserChangedCB
       * @param {Function} onActiveSpeakerVideoUserChanged
       * @return {Boolean} true or false
       */
      MeetingVideo_SetActiveSpeakerVideoUserChangedCB: function (onActiveSpeakerVideoUserChanged) {
        if (_addon && onActiveSpeakerVideoUserChanged && onActiveSpeakerVideoUserChanged instanceof Function) {
          _onActiveSpeakerVideoUserChanged = onActiveSpeakerVideoUserChanged;
          return true;
        }
        return false;
      },
      /**
       * Set onActiveVideoUserChanged callback.
       * @method MeetingVideo_SetActiveVideoUserChangedCB
       * @param {Function} onActiveVideoUserChanged
       * @return {Boolean} true or false
       */
      MeetingVideo_SetActiveVideoUserChangedCB: function (onActiveVideoUserChanged) {
        if (_addon && onActiveVideoUserChanged && onActiveVideoUserChanged instanceof Function) {
          _onActiveVideoUserChanged = onActiveVideoUserChanged;
          return true;
        }
        return false;
      },
      /**
       * Set onSpotlightedUserListChangeNotification callback.
       * @method MeetingVideo_SetSpotlightedUserListChangeNotificationCB
       * @param {Function} onSpotlightedUserListChangeNotification
       * @return {Boolean} true or false
       */
      MeetingVideo_SetSpotlightedUserListChangeNotificationCB: function (onSpotlightedUserListChangeNotification) {
        if (_addon && onSpotlightedUserListChangeNotification && onSpotlightedUserListChangeNotification instanceof Function) {
          _onSpotlightedUserListChangeNotification = onSpotlightedUserListChangeNotification;
          return true;
        }
        return false;
      },
      /**
       * Turn off the user's own video.
       * @method MeetingVideo_MuteVideo
       * @param {Number} userid Specifies which the user's video to mute
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid for both Zoom style and customize user interface mode.
       */
      MeetingVideo_MuteVideo: function(opts) {
        if(_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let MuteVideoParams = new messages.MuteVideoParams();
            MuteVideoParams.setUserid(Number(userid));
            let bytes = MuteVideoParams.serializeBinary();
            return _addon.MuteVideo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Turn on the user's own video.
       * @method MeetingVideo_UnMuteVideo
       * @param {Number} userid Specifies which the user's video to unmute
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid for both Zoom style and customize user interface mode.
       */
      MeetingVideo_UnMuteVideo: function (opts) {
        if(_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let UnMuteVideoParams = new messages.UnMuteVideoParams();
            UnMuteVideoParams.setUserid(Number(userid));
            let bytes = UnMuteVideoParams.serializeBinary();
            return _addon.UnMuteVideo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Determines if it is able to pin the video of the specified user to the first view.
       * @method MeetingVideo_CanPinToFirstView
       * @param {Number} userid Specifies the user ID to be determined.
       * @return {Object} {err, result} err is SDKError. result is PinResult and validates only when err is SDKERR_SUCCESS.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_CanPinToFirstView: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let CanPinToFirstViewParams = new messages.PinVideoToFirstViewParams();
            CanPinToFirstViewParams.setUserid(Number(userid));
            let bytes = CanPinToFirstViewParams.serializeBinary();
            return _addon.CanPinToFirstView(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Pin the video of the assigned user to the first view.
       * @method MeetingVideo_PinVideoToFirstView
       * @param {Number} userid Specifies which the user's video to pin
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_PinVideoToFirstView: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let PinVideoToFirstViewParams = new messages.PinVideoToFirstViewParams();
            PinVideoToFirstViewParams.setUserid(Number(userid));
            let bytes = PinVideoToFirstViewParams.serializeBinary();
            return _addon.PinVideoToFirstView(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Unpin all the videos from the first view.
       * @method MeetingVideo_UnPinAllVideosFromFirstView
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_UnPinAllVideosFromFirstView: function () {
        if (_addon) {
          return _addon.UnPinAllVideosFromFirstView();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Gets the list of all the pinned user in the first view.
       * @method MeetingVideo_GetPinnedUserListFromFirstView
       * @return {Array} The list of the pinned user in the first view, or an empty array if the operation fails.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_GetPinnedUserListFromFirstView: function () {
        if (_addon) {
          return _addon.GetPinnedUserListFromFirstView();
        }
        return [];
      },
      /**
       * Determines if it is able to pin the video of the specified user to the second view.
       * @method MeetingVideo_CanPinToSecondView
       * @param {Number} userid Specifies the user ID to be determined.
       * @return {Object} {err, result} err is SDKError. result is PinResult and validates only when err is SDKERR_SUCCESS.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_CanPinToSecondView: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let CanPinToSecondViewParams = new messages.PinVideoToFirstViewParams();
            CanPinToSecondViewParams.setUserid(Number(userid));
            let bytes = CanPinToSecondViewParams.serializeBinary();
            return _addon.CanPinToSecondView(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Pin the video of the assigned user to the second view.
       * @method MeetingVideo_PinVideoToSecondView
       * @param {Number} userid Specifies which the user's video to pin
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_PinVideoToSecondView: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let PinVideoToSecondViewParams = new messages.PinVideoToFirstViewParams();
            PinVideoToSecondViewParams.setUserid(Number(userid));
            let bytes = PinVideoToSecondViewParams.serializeBinary();
            return _addon.PinVideoToSecondView(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Gets the list of all the pinned user in the second view.
       * @method MeetingVideo_GetPinnedUserListFromSecondView
       * @return {Array} The list of the pinned user in the second view, or an empty array if the operation fails.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_GetPinnedUserListFromSecondView: function () {
        if (_addon) {
          return _addon.GetPinnedUserListFromSecondView();
        }
        return [];
      },
      /**
       * Determines if it is able to spotlight the video of the specified user in the meeting.
       * @method MeetingVideo_CanSpotlight
       * @param {Number} userid Specifies the user ID to be determined.
       * @return {Object} {err, result} err is SDKError. result is SpotlightResult and validates only when err is SDKERR_SUCCESS.
       * @note Valid for both Zoom style and customize user interface mode.
       */
      MeetingVideo_CanSpotlight: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let CanSpotlightParams = new messages.SpotlightVideoParams();
            CanSpotlightParams.setUserid(Number(userid));
            let bytes = CanSpotlightParams.serializeBinary();
            return _addon.CanSpotlight(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Determines if it is able to unspotlight the video of the specified user in the meeting.
       * @method MeetingVideo_CanUnSpotlight
       * @param {Number} userid Specifies the user ID to be determined.
       * @return {Object} {err, result} err is SDKError. result is SpotlightResult and validates only when err is SDKERR_SUCCESS.
       * @note Valid for both Zoom style and customize user interface mode.
       */
      MeetingVideo_CanUnSpotlight: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let CanUnSpotlightParams = new messages.SpotlightVideoParams();
            CanUnSpotlightParams.setUserid(Number(userid));
            let bytes = CanUnSpotlightParams.serializeBinary();
            return _addon.CanUnSpotlight(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Spotlight the video of the assigned user to the first view.
       * @method MeetingVideo_SpotlightVideo
       * @param {Number} userid Specifies which the user's video to pin
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid for both Zoom style and customize user interface mode.
       */
      MeetingVideo_SpotlightVideo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let SpotlightVideoParams = new messages.SpotlightVideoParams();
            SpotlightVideoParams.setUserid(Number(userid));
            let bytes = SpotlightVideoParams.serializeBinary();
            return _addon.SpotlightVideo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Unspotlight the video of the assigned user.
       * @method MeetingVideo_UnSpotlightVideo
       * @param {Number} userid Specifies which the user's video to unspotlight
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid for both Zoom style and customize user interface mode.
       */
      MeetingVideo_UnSpotlightVideo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let UnSpotlightVideoParams = new messages.SpotlightVideoParams();
            UnSpotlightVideoParams.setUserid(Number(userid));
            let bytes = UnSpotlightVideoParams.serializeBinary();
            return _addon.UnSpotlightVideo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Unspotlight all videos.
       * @method MeetingVideo_UnSpotlightAllVideos
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid for both Zoom style and customize user interface mode.
       */
      MeetingVideo_UnSpotlightAllVideos: function () {
        if (_addon) {
          return _addon.UnSpotlightAllVideos();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Gets the list of all the spotlighted user in the meeting.
       * @method MeetingVideo_GetSpotlightedUserList
       * @return {Array} The list of the spotlighted user in the meeting, or an empty array if the operation fails.
       * @note Valid for both Zoom style and customize user interface mode.
       */
      MeetingVideo_GetSpotlightedUserList: function () {
        if (_addon) {
          return _addon.GetSpotlightedUserList();
        }
        return [];
      },
      /**
      * Display or not the user who does not turn on the video in the video all mode.
      * @method MeetingVideo_HideOrShowNoVideoUserOnVideoWall
      * @param {Boolean} bHide bHide or not
      * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
      * @note Valid only for Zoom style user interface mode.
      */
      MeetingVideo_HideOrShowNoVideoUserOnVideoWall: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bHide = clientOpts.bHide;
          try {
            let HideOrShowNoVideoUserOnVideoWallParams = new messages.HideOrShowNoVideoUserOnVideoWallParams();
            HideOrShowNoVideoUserOnVideoWallParams.setBhide(bHide);
            let bytes = HideOrShowNoVideoUserOnVideoWallParams.serializeBinary();
            return _addon.HideOrShowNoVideoUserOnVideoWall(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Set the video quality preference that automatically adjust user's video to prioritize frame rate versus resolution based on the current bandwidth available.
       * @method MeetingVideo_SetVideoQualityPreference
       * @param {Number} mode 0: Balance mode; 1: Smoothness mode; 2: Sharpness mode; 3: Custom mode
       * @param {Number} minimumFrameRate 0 for the default value,minimum_frame_rate should be less than maximum_frame_rate, range: from 0 to 30 .out of range for frame-rate will use default frame-rate of Zoom
       * @param {Number} maximumFrameRate 0 for the default value,maximum_frame_rate should be less and equal than 30, range: from 0 to 30.out of range for frame-rate will use default frame-rate of Zoom
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      MeetingVideo_SetVideoQualityPreference: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let mode = clientOpts.mode;
          let minimumFrameRate = clientOpts.minimumFrameRate;
          let maximumFrameRate = clientOpts.maximumFrameRate;
          try {
            let SetVideoQualityPreferenceParams = new messages.SetVideoQualityPreferenceParams();
            SetVideoQualityPreferenceParams.setMode(mode);
            SetVideoQualityPreferenceParams.setMinimumframerate(minimumFrameRate);
            SetVideoQualityPreferenceParams.setMaximumframerate(maximumFrameRate);
            let bytes = SetVideoQualityPreferenceParams.serializeBinary();
            return _addon.SetVideoQualityPreference(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Unpin the video of the assigned user from the first view.
       * @method MeetingVideo_UnPinVideoFromFirstView
       * @param {Number} userid Specifies the user ID to be unpinned.
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_UnPinVideoFromFirstView: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let UnPinVideoFromFirstViewParams = new messages.UnPinVideoFromFirstViewParams();
            UnPinVideoFromFirstViewParams.setUserid(Number(userid));
            let bytes = UnPinVideoFromFirstViewParams.serializeBinary();
            return _addon.UnPinVideoFromFirstView(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Unpin the video of the assigned user from the second view.
       * @method MeetingVideo_UnPinVideoFromSecondView
       * @param {Number} userid Specifies the user ID to be unpinned.
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       * @note Valid only for Zoom style user interface mode.
       */
      MeetingVideo_UnPinVideoFromSecondView: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          try {
            let UnPinVideoFromSecondViewParams = new messages.UnPinVideoFromSecondViewParams();
            UnPinVideoFromSecondViewParams.setUserid(Number(userid));
            let bytes = UnPinVideoFromSecondViewParams.serializeBinary();
            return _addon.UnPinVideoFromSecondView(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Gets the local video order list.
       * @method MeetingVideo_GetLocalVideoOrderList
       * @return {Array} The local video order list, or an empty array if the operation fails.
       * @note This list reflects the local video order as last received via the onLocalVideoOrderUpdated callback.
       * The local video order is updated whenever onLocalVideoOrderUpdated is triggered.
       */
      MeetingVideo_GetLocalVideoOrderList: function () {
        if (_addon) {
          return _addon.GetLocalVideoOrderList();
        }
        return [];
      },
      /**
       * Determines if the following host video order feature is supported.
       * @method MeetingVideo_IsSupportFollowHostVideoOrder
       * @return {Boolean} true indicates to support the following host video order feature.
       */
      MeetingVideo_IsSupportFollowHostVideoOrder: function () {
        if (_addon) {
          return _addon.IsSupportFollowHostVideoOrder();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Enables or disable follow host video order mode.
       * @method MeetingVideo_EnableFollowHostVideoOrder
       * @param {Boolean} bEnable true indicates to set to enable the follow host video order mode.
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      MeetingVideo_EnableFollowHostVideoOrder: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableFollowHostVideoOrderParams = new messages.EnablePlayChimeWhenEnterOrExitParams();
            EnableFollowHostVideoOrderParams.setBenable(bEnable);
            let bytes = EnableFollowHostVideoOrderParams.serializeBinary();
            return _addon.EnableFollowHostVideoOrder(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Determines if the follow host video mode is enabled.
       * @method MeetingVideo_IsFollowHostVideoOrderOn
       * @return {Boolean} true indicates to enable the mode.
       */
      MeetingVideo_IsFollowHostVideoOrderOn: function () {
        if (_addon) {
          return _addon.IsFollowHostVideoOrderOn();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Gets the host video order list.
       * @method MeetingVideo_GetVideoOrderList
       * @return {Array} The host video order list, or an empty array if the operation fails.
       * @note This method only returns the order list based on the host's video order (hostVideoOrder).
       * If the host has not updated the video order, this list will be empty.
       */
      MeetingVideo_GetVideoOrderList: function () {
        if (_addon) {
          return _addon.GetVideoOrderList();
        }
        return [];
      }
    };
  };

  return {
    getInstance: function(opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomMeetingVideo: ZoomMeetingVideo
}
