#ifndef ZUI_DIALOG_INTERFACE_H_
#define ZUI_DIALOG_INTERFACE_H_

#include <memory>
#include <functional>

/**
 * @brief Base interface for all ZUI dialogs
 * 
 * All dialog components should implement this interface to enable
 * unified management through AlertDialogMgr.
 */
class IZUIDialog
{
public:
  virtual ~IZUIDialog() = default;

  virtual void Show(void* parent = nullptr) = 0;
  virtual void Close() = 0;
  virtual bool IsVisible() = 0;
};

/**
 * @brief Factory interface for creating dialog instances
 */
class IZUIDialogFactory
{
public:
  virtual ~IZUIDialogFactory() = default;
  virtual std::shared_ptr<IZUIDialog> Create() = 0;
};

#endif // ZUI_DIALOG_INTERFACE_H_
