#ifndef __ZUI_VIDEO_MGR_HUB_INTERFACE_H__
#define __ZUI_VIDEO_MGR_HUB_INTERFACE_H__

#include <string>

class IZUIMeetingHostControlMgr;
class IZUIMeetingSettingMgr;
class IZUIMeetingInfoMgr;
class IZUVoiceTranslationMgr;
class IZUIMeetingEncryptionMgr;
class IZUIMeetingAiFeaturesMgr;
class IZUIMeetingTranscriptMgr;
class IZUIMeetingClinicalNoteMgr;
class IZUIMeetingLanguageMgr;
class IArchiveCustomConfirmAlertSink;
class IZUILowerThirdSettingsMgr;
class IZUIDocSharePermissionDialogMgr;

class IZuiVideoMgrBase
{
public:
  virtual ~IZuiVideoMgrBase() {}
  virtual void Init() = 0;
  virtual void Uninit() = 0;
};

class IAlertDialogMgr : public IZuiVideoMgrBase
{
public:
  IAlertDialogMgr() {}
  virtual ~IAlertDialogMgr() {}

  virtual void SetArchiveCustomConfirmAlertSink(IArchiveCustomConfirmAlertSink* sink) {}
  virtual void ShowArchiveCustomConfirmDialog(const std::string& title,
                                              const std::string& content,
                                              const std::string& no_archive_warning_text = "",
                                              const std::string& option_archive_text = "Archive this meeting",
                                              const std::string& option_no_archive_text = "Don't archive this meeting") {}
  virtual void HideArchiveCustomConfirmDialog() {}
  virtual void SetWindowParent(void* parent) {}
};

class IArchiveCustomConfirmAlertSink
{
public:
  virtual ~IArchiveCustomConfirmAlertSink() {}

  virtual void OnArchiveCustomConfirmJoin(bool archive_this_meeting) {}
  virtual void OnArchiveCustomConfirmLeave() {}
};

class IZuiVideoMgrHub : public IZuiVideoMgrBase
{
public:
	virtual ~IZuiVideoMgrHub() {}
	virtual IAlertDialogMgr* GetAlertDialogMgr() = 0;

  virtual IZUIMeetingSettingMgr* GetMeetingSettingMgr() = 0;

  virtual IZUIMeetingHostControlMgr* GetHostControlMgr() = 0;

  virtual IZUIMeetingInfoMgr* GetMeetingInfoMgr() = 0;
    
  virtual IZUVoiceTranslationMgr* GetVoiceTranslationMgr() = 0;

  virtual IZUIMeetingEncryptionMgr* GetMeetingEncryptionMgr() = 0;

  virtual IZUIMeetingAiFeaturesMgr* GetMeetingAiFeaturesMgr() = 0;

  virtual IZUIMeetingTranscriptMgr* GetMeetingTranscriptMgr() = 0;

  virtual IZUIDocSharePermissionDialogMgr* GetDocSharePermissionDialogMgr() { return nullptr; }

  virtual IZUIMeetingClinicalNoteMgr* GetMeetingClinicalNoteMgr() = 0;
    
  virtual IZUIMeetingLanguageMgr* GetMeetingLanguageMgr() = 0;

  virtual IZUILowerThirdSettingsMgr* GetLowerThirdSettingsMgr() = 0;
};

#endif //__ZUI_VIDEO_MGR_HUB_INTERFACE_H__
