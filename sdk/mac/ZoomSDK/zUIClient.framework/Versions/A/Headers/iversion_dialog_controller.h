#ifndef IVERSION_DIALOG_CONTROLLER_H
#define IVERSION_DIALOG_CONTROLLER_H

#include "zUI_stdafx.h"
#include "zUI/view.h"

#include <memory>
#include <string>

class ZUIClient_API IVersionDialogSink
{
public:
  virtual ~IVersionDialogSink() = default;
  virtual void OnCloseClick() = 0;
  virtual bool OnCopyVersion(const std::string& versionText) = 0;
  virtual void OnMoreInfoClick() {}
};

class ZUIClient_API IVersionDialogController
{
public:
  virtual ~IVersionDialogController() = default;

  virtual void ShowDialog(void* parent = nullptr) = 0;
  virtual void HideDialog() = 0;
  virtual void CloseDialog() = 0;
  virtual bool IsDialogVisible() const = 0;
  virtual void* GetNativeDialogHandle() const = 0;
  virtual void SetLogoImage(const std::string& image) = 0;

  virtual void SetSink(IVersionDialogSink* sink) = 0;
  virtual IVersionDialogSink* GetSink() = 0;
  virtual std::shared_ptr<zui::View> GetView() = 0;
  virtual void RemoveView() = 0;
};

#endif // IVERSION_DIALOG_CONTROLLER_H
