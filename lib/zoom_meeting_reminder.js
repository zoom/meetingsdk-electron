let { ZoomSDKError, ActionType, FeatureEnableOption } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

var ZoomMeetingReminder = (function () {
  var instance;
  /**
   * Zoom Meeting Reminder
   * The AI Companion brand has been retired. AI-powered features are now more deeply integrated throughout Zoom Workplace. Existing APIs and SDKs that reference AI Companion will continue to function as before to ensure backward compatibility.
   * @module zoom_meeting_reminder
   * @param {Function} onReminderNotify Callback event of the reminder dialog show
   * @param {Function} onEnableReminderNotify Callback event of the enable reminder dialog show
   * @return {ZoomMeetingReminder}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingReminderCtrl() || null;
    let _onReminderNotify = clientOpts.onReminderNotify || null;
    let _onEnableReminderNotify = clientOpts.onEnableReminderNotify || null;

    /**
     * Callback event of the reminder dialog show.
     * @event onReminderNotify
     * @param {Object} content The detail content in the reminder dialog with the following properties:
     *   - type: The type of the reminder {@link MeetingReminderType}
     *   - title: The title of the reminder dialog content
     *   - content: The detail content of the reminder dialog content
     *   - is_blocking: Whether block the user join or stay in the meeting
     *   - actionType: The type of the action which user should take after receiving this reminder content {@link ActionType}
     */
    function onReminderNotify(content) {
      let meeting_reminder = {
        type: content.type,
        title: content.title,
        content: content.content,
        is_blocking: content.is_blocking,
        actionType: content.actionType
      }
      if (_onReminderNotify) {
        _onReminderNotify(meeting_reminder)
      }
    }

    /**
     * Callback event of the enable reminder dialog show.
     * @event onEnableReminderNotify
     * @param {Object} content The detail content in the reminder dialog with the following properties:
     *   - type: The type of the reminder {@link MeetingReminderType}
     *   - title: The title of the reminder dialog content
     *   - content: The detail content of the reminder dialog content
     *   - is_blocking: Whether block the user join or stay in the meeting
     *   - actionType: The type of the action which user should take after receiving this reminder content {@link ActionType}
     */
    function onEnableReminderNotify(content) {
      let meeting_reminder = {
        type: content.type,
        title: content.title,
        content: content.content,
        is_blocking: content.is_blocking,
        actionType: content.actionType
      }
      if (_onEnableReminderNotify) {
        _onEnableReminderNotify(meeting_reminder)
      }
    }

    if (_addon) {
      _addon.SetOnReminderNotifyCB(onReminderNotify);
      _addon.SetOnEnableReminderNotifyCB(onEnableReminderNotify);
    }

    return {
      // Public methods and variables
      /**
       * Set onReminderNotify callback.
       * @method SetOnReminderNotifyCB
       * @param {Function} onReminderNotify
       * @return {Boolean} true or false
       */
      SetOnReminderNotifyCB: function (onReminderNotify) {
        if (_addon && onReminderNotify && onReminderNotify instanceof Function) {
          _onReminderNotify = onReminderNotify;
          return true;
        }
        return false;
      },
      /**
       * Ignore the reminder.
       * @method Ignore
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      Ignore: function () {
        if (_addon) {
          return _addon.Ignore();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Accept the reminder.
       * @method Accept
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      Accept: function () {
        if (_addon) {
          return _addon.Accept();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Decline the reminder.
       * @method Decline
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      Decline: function () {
        if (_addon) {
          return _addon.Decline();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Set onEnableReminderNotify callback.
       * @method SetOnEnableReminderNotifyCB
       * @param {Function} onEnableReminderNotify
       * @return {Boolean} true or false
       */
      SetOnEnableReminderNotifyCB: function (onEnableReminderNotify) {
        if (_addon && onEnableReminderNotify && onEnableReminderNotify instanceof Function) {
          _onEnableReminderNotify = onEnableReminderNotify;
          return true;
        }
        return false;
      },
      /**
       * Sets the option indicating which meetings feature will be enabled for.
       * @method SetEnableOption
       * @param {Number} option Specify the option {@link FeatureEnableOption}
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      SetEnableOption: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let option = typeof clientOpts.option === 'number'
            ? clientOpts.option
            : FeatureEnableOption.EnableOption_Once;
          try {
            let SetEnableOptionParams = new messages.SetEnableOptionParams();
            SetEnableOptionParams.setOption(option);
            let bytes = SetEnableOptionParams.serializeBinary();
            return _addon.SetEnableOption(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Starts the feature.
       * @method StartEnable
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      StartEnable: function () {
        if (_addon) {
          return _addon.StartEnable();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Decline the reminder.
       * @method DeclineEnable
       * @param {Boolean} bDeclineAll true indicates decline all reminders,and participants cannot send requests again until the host changes the setting. false means that the host declines only this specific request, not all requests.
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      DeclineEnable: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bDeclineAll = clientOpts.bDeclineAll;
          try {
            let DeclineEnableParams = new messages.DeclineEnableParams();
            DeclineEnableParams.setBdeclineall(bDeclineAll);
            let bytes = DeclineEnableParams.serializeBinary();
            return _addon.DeclineEnable(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Ignore the reminder.
       * @method IgnoreEnable
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      IgnoreEnable: function () {
        if (_addon) {
          return _addon.IgnoreEnable();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Sets not show the disclaimer in subsequent meetings.
       * @method SetHideFeatureDisclaimers
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      SetHideFeatureDisclaimers: function () {
        if (_addon) {
          return _addon.SetHideFeatureDisclaimers();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Sets the customized config of multi-reminder disclaimer.
       * @method SetMultiReminderDisclaimerUIConfig
       * @param {Number} left Specifies the X-axis coordinate of the top-left corner of the multi-reminder window in the parent window.
       * @param {Number} top Specifies the Y-axis coordinate of the top-left corner of the multi-reminder window in the parent window.
       * @param {String} parentWindowHandle Specifies the hexadecimal handle of the parent window.
       * @param {Number} backgroundColor Specifies the background color of the multi-reminder window.
       * @note Valid for user custom interface mode only.
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      SetMultiReminderDisclaimerUIConfig: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let left = clientOpts.left || 0;
          let top = clientOpts.top || 0;
          let parentWindowHandle = clientOpts.parentWindowHandle || '';
          let backgroundColor = typeof clientOpts.backgroundColor === 'number'
            ? clientOpts.backgroundColor
            : 0xffffff;
          try {
            let SetMultiReminderDisclaimerUIConfigParams = new messages.SetMultiReminderDisclaimerUIConfigParams();
            SetMultiReminderDisclaimerUIConfigParams.setLeft(left);
            SetMultiReminderDisclaimerUIConfigParams.setTop(top);
            SetMultiReminderDisclaimerUIConfigParams.setParentwindowhandle(parentWindowHandle);
            SetMultiReminderDisclaimerUIConfigParams.setBackgroundcolor(backgroundColor);
            let bytes = SetMultiReminderDisclaimerUIConfigParams.serializeBinary();
            return _addon.SetMultiReminderDisclaimerUIConfig(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Update the position and size of multi-reminder disclaimer window when its parent window moves or changes size.
       * @method UpdateMultiReminderDisclaimerUI
       * @note This interface should be invoked when the OnSize and OnMove messages of the parent window recieved. Valid for user custom interface mode only.
       * @return {Number} If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
       */
      UpdateMultiReminderDisclaimerUI: function () {
        if (_addon) {
          return _addon.UpdateMultiReminderDisclaimerUI();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts)
      }
      return instance
    }
  };
})();

module.exports = {
  ZoomMeetingReminder: ZoomMeetingReminder
}
