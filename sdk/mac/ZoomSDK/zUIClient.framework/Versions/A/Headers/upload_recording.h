#ifndef UPLOAD_RECORDING_H
#define UPLOAD_RECORDING_H

#include "zUI_stdafx.h"
#include "zui_client_data_define.h"

enum class UploadRecordType : uint32_t {
    kUploading,
    kSuccess,
    kFaild,
};

class ZUIClient_API CUploadRecordPopupModel : public IInitializable, public zui::IZUIWindowEventSink
{
public:
    CUploadRecordPopupModel();
    ~CUploadRecordPopupModel();
    
    void initializeState() override;
    void initializeStateHandler() override;
    
    void ShowDialog();
    void HideDialog();
    void CloseDialog();
    bool IsDialogVisible();
    
    struct ProgressData
    {
        std::string _title;
        zui::State<float> _progressValue;
        zui::State<bool> _isPaused;
        bool operator==(const ProgressData& other) const{
          return _title == other._title && _progressValue == other._progressValue && _isPaused == other._isPaused;
        }
    };
    
public:
    // native client set
    zui::State<UploadRecordType> _uploadType;
    zui::State<bool> _needShowRetry;
    zui::State<bool> _isPaused;
    zui::State<bool> _isNotInMeeting;
    BtnProperty2 _rightBtn;
    BtnProperty2 _leftBtn;
    zui::State<std::vector<zui::any>> _ProgressDatas;
    void UpdateProgressValue(int index, float progressValue);
    
    virtual void OnWndHandleDestroyed(size_t windowID);

public:
    zui::State<std::string> _uploadTitle;
    zui::State<std::string> _uploadDesc;
    zui::State<std::string> _iconName;
    zui::State<bool> _needShowProgress;

private:
    std::shared_ptr<zui::ZUIWindow> _dialog;
    void UpdateData();
    void UpdatePausedState();
};

#endif
