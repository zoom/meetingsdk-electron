const { ZoomSDKError } = require('./settings.js');

var ZoomSettingStatisticCtrl = (function () {
  var instance;
  function init(opts) {
    let clientOpts = opts || {};
    let _addon = clientOpts.addon.GetSettingStatisticCtrl() || null;

    return {
      Setting_QueryOverallStatisticInfo: function () {
        if (_addon) {
          return _addon.QueryOverallStatisticInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
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
  ZoomSettingStatisticCtrl: ZoomSettingStatisticCtrl
}
