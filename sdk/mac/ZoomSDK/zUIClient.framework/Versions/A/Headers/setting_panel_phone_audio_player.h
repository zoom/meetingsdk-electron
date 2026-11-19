#ifndef __PHONE_AUDIO_PLAYER_H__
#define __PHONE_AUDIO_PLAYER_H__

#include <signals/signals.h>
#include "zPTApp/sip/sipcall_audio_file_player_api.h"
#include "cmmlib/CmmGUID.h"

namespace zui {

  class ISettingPanelPhoneAudioPlayer {
  public:
    virtual ~ISettingPanelPhoneAudioPlayer() = default;

    virtual NS_SIPCALL_APP::SIPAudioFilePlayerStatus GetPlayerStatus() = 0;
    virtual CmmUInt32 GetCurrentProgress() const = 0;  // ms
    virtual CmmUInt32 GetDuration() const = 0;  // ms
    virtual void StartPlay(const Cmm::CString& url, CmmUInt32 start_position) = 0;
    virtual void StopPlay() = 0;
    virtual void PausePlay() = 0;
    virtual void ResumePlay() = 0;
    virtual void ChangePlayProgress(CmmUInt32 start_position) = 0;  // ms

    // signal
    virtual signals2::signal2<void, NS_SIPCALL_APP::SIPAudioFilePlayerStatus, CmmUInt32>& OnPlayStatus() = 0;
    virtual signals2::signal2<void, CmmUInt32>& OnPlayProgressChanged() = 0;
    virtual signals2::signal2<void>& OnPlayTerminated() = 0;

    static Cmm::CString GenGuidString() {
      Cmm::CmmGUID guid;
      Cmm::CString str_guid;
      str_guid = guid.GetStr();
      if (str_guid.IsEmpty()) return _T("");
      if (*(str_guid.begin()) == _T('{')) {
        str_guid.erase(str_guid.begin());
      }
      if (*(str_guid.rbegin()) == _T('}')) {
        str_guid.resize(str_guid.size() - 1);
      }
      return str_guid;

    }
  };
}

#endif // __PHONE_AUDIO_PLAYER_H__