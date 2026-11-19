let { ZoomSDKError } = require("./settings.js");
const messages = require("./electron_sdk_pb.js");

var ZoomMeetingCloseCaption = (function () {
    var instance;
  /**
   * Zoom Close Captions
   * @module zoom_meeting_close_caption
   * @param {Function} onLiveTranscriptionMsgInfoReceived Callback event used to inform the user once a live transcription message is received.
   * @param {Function} onOriginalLanguageMsgReceived Callback event used to inform the user once the original language message is received.
   * @return {ZoomMeetingCloseCaption}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingCloseCaptionCtrl() || null;

    let _onLiveTranscriptionMsgInfoReceived = clientOpts.onLiveTranscriptionMsgInfoReceived || null;
    let _onOriginalLanguageMsgReceived = clientOpts.onOriginalLanguageMsgReceived || null;

    /**
     * Live transcription message received callback.
     * @event onLiveTranscriptionMsgInfoReceived
     * @param {Object} messageInfo The live transcription message with the following properties:
     *   - messageID: The message ID of the current message.
     *   - speakerID: The speaker's ID.
     *   - speakerName: The speaker's name.
     *   - messageContent: The content of the current message.
     *   - timeStamp: The timestamp of the current message.
     *   - messageType: The type of the current message.
     */
    function onLiveTranscriptionMsgInfoReceived(messageInfo) {
      let meeting_close_caption = {
        messageID: messageInfo.messageID,
        speakerID: messageInfo.speakerID,
        speakerName: messageInfo.speakerName,
        messageContent: messageInfo.messageContent,
        timeStamp: messageInfo.timeStamp,
        messageType: messageInfo.messageType,
      }
      if (_onLiveTranscriptionMsgInfoReceived) {
        _onLiveTranscriptionMsgInfoReceived(meeting_close_caption);
      }
    }

    /**
     * Original language message received callback.
     * @event onOriginalLanguageMsgReceived
     * @param {Object} messageInfo The spoken language message with the following properties:
     *   - messageID: The message ID of the current message.
     *   - speakerID: The speaker's ID.
     *   - speakerName: The speaker's name.
     *   - messageContent: The content of the current message.
     *   - timeStamp: The timestamp of the current message.
     *   - messageType: The type of the current message.
     */
    function onOriginalLanguageMsgReceived(messageInfo) {
        let meeting_close_caption = {
            messageID: messageInfo.messageID,
            speakerID: messageInfo.speakerID,
            speakerName: messageInfo.speakerName,
            messageContent: messageInfo.messageContent,
            timeStamp: messageInfo.timeStamp,
            messageType: messageInfo.messageType,
        }
        if (_onOriginalLanguageMsgReceived) {
            _onOriginalLanguageMsgReceived(meeting_close_caption);
        }
    }

    if (_addon) {
      _addon.SetOnLiveTranscriptionMsgInfoReceivedCB(onLiveTranscriptionMsgInfoReceived);
      _addon.SetOnOriginalLanguageMsgReceivedCB(onOriginalLanguageMsgReceived);
    }

    return {
      // Public methods and variables
      /**
       * Set onLiveTranscriptionMsgInfoReceived callback.
       * @method SetOnLiveTranscriptionMsgInfoReceivedCB
       * @param {Function} onLiveTranscriptionMsgInfoReceived
       * @return {Boolean} true or false
       */
      SetOnLiveTranscriptionMsgInfoReceivedCB: function (onLiveTranscriptionMsgInfoReceived) {
        if (_addon && onLiveTranscriptionMsgInfoReceived && onLiveTranscriptionMsgInfoReceived instanceof Function) {
          _onLiveTranscriptionMsgInfoReceived = onLiveTranscriptionMsgInfoReceived;
          return true;
        }
        return false;
      },
      /**
       * Set onOriginalLanguageMsgReceived callback.
       * @method SetOnOriginalLanguageMsgReceivedCB
       * @param {Function} onOriginalLanguageMsgReceived
       * @return {Boolean} true or false
       */
      SetOnOriginalLanguageMsgReceivedCB: function (onOriginalLanguageMsgReceived) {
        if (_addon && onOriginalLanguageMsgReceived && onOriginalLanguageMsgReceived instanceof Function) {
          _onOriginalLanguageMsgReceived = onOriginalLanguageMsgReceived;
          return true;
        }
        return false;
      },
      GetAvailableMeetingSpokenLanguages: function () {
        if (_addon) {
          try {
            let languageList = _addon.GetAvailableMeetingSpokenLanguages();
            if (languageList) {
              return languageList;
            }
            return [];
          } catch (error) {
            return ZoomSDKError.SDKERR_UNINITIALIZE;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      GetAvailableTranslationLanguages: function () {
        if (_addon) {
          try {
            let languageList = _addon.GetAvailableTranslationLanguages();
            if (languageList) {
              return languageList;
            }
            return [];
          } catch (error) {
            return ZoomSDKError.SDKERR_UNINITIALIZE;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      GetTranslationLanguage: function () {
        if (_addon) {
          try {
            let language = _addon.GetTranslationLanguage();
            return language;
          } catch (error) {
            return ZoomSDKError.SDKERR_UNINITIALIZE;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      SetTranslationLanguage: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let languageID = clientOpts.languageID;
          if (languageID === undefined || languageID === null) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let SetTranslationLanguageParams =
              new messages.SetTranslationLanguageParams();
            SetTranslationLanguageParams.setLanguageid(Number(languageID));
            let bytes = SetTranslationLanguageParams.serializeBinary();
            return _addon.SetTranslationLanguage(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      SetMeetingSpokenLanguage: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let languageID = clientOpts.languageID;
          let isForAll = clientOpts.isForAll;
          if (languageID === undefined || languageID === null) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let SetMeetingSpokenLanguageParams =
              new messages.SetMeetingSpokenLanguageParams();
            SetMeetingSpokenLanguageParams.setLanguageid(Number(languageID));
            SetMeetingSpokenLanguageParams.setIsforall(isForAll);
            let bytes = SetMeetingSpokenLanguageParams.serializeBinary();
            return _addon.SetMeetingSpokenLanguage(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      EnableCaptions: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let enable = clientOpts.enable;
          try {
            let EnableCaptionsParams = new messages.EnableCaptionsParams();
            EnableCaptionsParams.setEnable(enable);
            let bytes = EnableCaptionsParams.serializeBinary();
            return _addon.EnableCaptions(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      StartLiveTranscription: function () {
        if (_addon) {
          try {
            return _addon.StartLiveTranscription();
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      StopLiveTranscription: function () {
        if (_addon) {
          try {
            return _addon.StopLiveTranscription();
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      EnableReceiveSpokenLanguageContent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let enable = clientOpts.enable;
          try {
            let EnableReceiveSpokenLanguageContentParams =
              new messages.EnableReceiveSpokenLanguageContentParams();
            EnableReceiveSpokenLanguageContentParams.setEnable(enable);
            let bytes =
              EnableReceiveSpokenLanguageContentParams.serializeBinary();
            return _addon.EnableReceiveSpokenLanguageContent(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      IsReceiveSpokenLanguageContentEnabled: function () {
        if (_addon) {
          try {
            return _addon.IsReceiveSpokenLanguageContentEnabled();
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      IsLiveTranscriptionFeatureEnabled: function () {
        if (_addon) {
          try {
            return _addon.IsLiveTranscriptionFeatureEnabled();
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      IsMultiLanguageTranscriptionEnabled: function () {
        if (_addon) {
          try {
            return _addon.IsMultiLanguageTranscriptionEnabled();
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      IsTextLiveTranslationEnabled: function () {
        if (_addon) {
          try {
            return _addon.IsTextLiveTranslationEnabled();
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
    };
  }

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    },
  };
})();

module.exports = {
  ZoomMeetingCloseCaption: ZoomMeetingCloseCaption,
}