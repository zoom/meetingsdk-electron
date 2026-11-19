#ifndef _ZUI_MODEL_OBSERVER_H_
#define _ZUI_MODEL_OBSERVER_H_

#include <memory>
#ifdef __MACOS__
#import <zUI/zui_data_define.h>
#import <zUI/any.h>
#else
#include "zui_data_define.h"
#include "any.h"
#endif

#define INVALID_BINDING_ID -1

namespace zui
{
class IStateObserver;

extern ZUI_API std::function<void(IStateObserver*)> g_reg_fun;

struct RegGuard
{
  explicit RegGuard(const std::function<void(IStateObserver*)>& f) {
    g_reg_fun = f;
  }

  ~RegGuard() {
    g_reg_fun = nullptr;
  }
};

enum class ModelDataType {
  kUnknown,
  // kChar,
  // kUChar,
  // kShort,
  // kUShort,
  kInt,
  kUInt,
  // kLong,
  // kULong,
  // kLongLong,
  // kULongLong,
  kFloat,
  kDouble,
  kBool,
  kString
};

class ZUI_API IStateObserver {
public:
  enum class Type { kModel, kState, kBind, kPublish };

  explicit IStateObserver(Type type);
  virtual ~IStateObserver() = default;

  virtual void OnUpdate(bool needNotifySwift) {}
  virtual void OnViewUpdate(bool needNotifySwift) {}
  virtual void OnInternalViewUpdate() {}
  virtual void Calc(){}
  virtual int UseCount() { return 1; }

  int GetBindId() const { return _bindId; }
  void SetBindId(int bindId) { _bindId = bindId; }

  bool IsState() { return _type == Type::kState; }
  
  // Swift interop (macOS only)
public:
  virtual void SetFromSwift(const zui::any& val) {}
#ifdef __MACOS__
  std::string GetNotifyName() { return _stateName; }
  ModelDataType GetDataType() { return _dataType; }
  void registerStateName(const std::string &stateName, ModelDataType type);
  void unregisterStateName();
#else
  std::string GetNotifyName() { return std::string(); }
  ModelDataType GetDataType() { return ModelDataType::kUnknown; }
  void registerStateName(const std::string &, ModelDataType) {}
  void unregisterStateName() {}
#endif

protected:
  void AddObserver(bool notify);
  void Move(int targetId);
  void Update(bool notify);

protected:
  int _bindId;
  Type _type;

#ifdef __MACOS__
  // Swift bind support (macOS only, saves ~36 bytes per Bind on other platforms)
  std::string _stateName;
  ModelDataType _dataType;
#endif
};

void ZUI_API ZUIStateDidChange(const std::string& notifyName, ModelDataType type, void* data);
void ZUI_API RemoveObserver(IStateObserver* observer);
void ZUI_API AddCalcObserver(std::shared_ptr<IStateObserver> calcState, int targetId);
void ZUI_API UpdateFromSwift(int targetId, const zui::any& value);

}

#endif
