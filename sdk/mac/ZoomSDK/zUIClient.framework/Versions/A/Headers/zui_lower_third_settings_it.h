#ifndef _ZUI_LOWER_THIRD_SETTINGS_IT_H_
#define _ZUI_LOWER_THIRD_SETTINGS_IT_H_

#include <memory>
#include <string>

#ifdef _WIN32
#include "zUI/view.h"
#include "zUIClient/zUI_stdafx.h"
#elif defined __MACOS__
#import <zUI/view.h>
#import <zUIClient/zUI_stdafx.h>
#else
#include "view.h"
#include "zUI_stdafx.h"
#endif

// Sink: ZUI -> OC. Fired whenever the user edits a control inside the
// dynamic Lower Third settings panel.
//
// Delivers a single-key delta per edit. The OC layer is responsible for
// routing each change to the correct destination (configJson / independent
// OC property / scene-level field).
//   * key       : the catalog item key that changed (e.g. "primaryText",
//                 "showNameTag", "alwaysShow").
//   * value_json: the new value, encoded as a JSON fragment so that it
//                 preserves type (string -> "\"abc\"", bool -> "true",
//                 number -> "12", etc.). Always non-empty.
class IZUILowerThirdSettingsSink
{
public:
  virtual ~IZUILowerThirdSettingsSink() = default;

  virtual void OnScopedFieldChanged(const std::string& key,
                                    const std::string& value_json) = 0;

  // Fired on the UI thread immediately before Hide() when the user picks a
  // template in the list (not on click-outside / deactivate). Must run
  // synchronously: Hide()/orderOut follows immediately, and AppKit will
  virtual void OnSelectorWindowWillHide() {}

  // Native host window the template-list popup should parent to (macOS:NSWindow*).
  virtual void* GetSelectorWindowParent() { return nullptr; }
};

// Mgr: OC -> ZUI. Owns cached catalog / settingJs / locale and exposes
// the rebuilt clientSettingJson as a zui::State that the View subscribes to.
class ZUIClient_API IZUILowerThirdSettingsMgr
{
public:
  virtual ~IZUILowerThirdSettingsMgr() = default;

  // OC must NOT delete the sink while the panel is alive. Pass nullptr to
  // detach.
  virtual void SetSink(IZUILowerThirdSettingsSink* sink) = 0;

  // Apply the global catalog JSON (raw text). Triggers internal rebuild.
  // Pass empty string to clear (panel renders nothing).
  virtual void ApplyCatalog(const std::string& catalog_json) = 0;

  // Reset all cached inputs (panel renders nothing afterwards).
  virtual void Reset() = 0;
    
  virtual void SetExternalValue(const std::string& key,
                                const std::string& value_json) = 0;

  virtual void ApplyAll(const std::string& setting_js,
                        const std::string& external_values_json) = 0;

  // Tear down the template-list window without Hide(). Mac parents the
  // list to Studio via GetSelectorWindowParent(); still Destroy on host
  // close so a nil-parent fallback (Windows, or Mac before the settings
  // view is in a window) cannot outlive Studio. Default is a no-op for stubs.
  virtual void DismissSelectorWindow() {}
};

// Public entry: the self-contained ZUI panel that renders the dynamic
// Lower Third settings. Embed via
//   [[ZuiNSView alloc] initWithView:CLowerThirdSettingsView()].
class ZUIClient_API CLowerThirdSettingsView
    : public zui::CustomView<CLowerThirdSettingsView>
{
public:
  CLowerThirdSettingsView() = default;
  ~CLowerThirdSettingsView() = default;

  std::shared_ptr<zui::ViewNode> Build() override;
};

#endif  // _ZUI_LOWER_THIRD_SETTINGS_IT_H_
