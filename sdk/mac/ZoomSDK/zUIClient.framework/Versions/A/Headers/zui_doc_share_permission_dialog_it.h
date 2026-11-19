#ifndef ZUI_DOC_SHARE_PERMISSION_DIALOG_IT_H_
#define ZUI_DOC_SHARE_PERMISSION_DIALOG_IT_H_

// Doc Share Permission dialog - pure UI component. Native owns business
// data (gather it from CmmShareAPI / ICmmDocsPermissionSetting), hands the
// dialog one self-contained Config per Show, and receives the user's choice
// through IZUIDocSharePermissionDialogSink. The dialog does not talk to UUI.
//   Windows: every Show creates a fresh modal popup; Hide tears it down.
//   macOS:   host embeds GetContentView(); Show/Hide are no-ops there.

#include <memory>

namespace zui { class View; }

// Document variant. Drives row layout and the UI-layer string lookup for
// the Share button label and persistent-access checkbox copy.
enum class DocShareDocType {
  kNone,
  kSlides,
  kCanvasDoc,
  kPaper,
  kSheets,
  kWhiteboard,
};

// Audience scope: who interacts with the doc.
enum class DocSharePermissionScope {
  kNone,
  kPresent,        // Presentation mode; participants view only.
  kCollaborate,    // Edit / comment mode; scoped by permission level below.
};

// Per-scope action level. Cumulative ladder: kEdit implies kComment + kView,
// kComment implies kView. Enum order encodes the ladder so a single
// `max_level` value in DocSharePermissionConfig fully determines the
// dropdown option list.
enum class DocSharePermissionLevel {
  kNone,
  kView,
  kComment,
  kEdit,
};

struct DocSharePermissionConfig {
  DocShareDocType doc_type = DocShareDocType::kNone;
  DocSharePermissionLevel max_level = DocSharePermissionLevel::kEdit;
  bool persistent_access_enabled = true;
};

// Business-outcome sink. Fires exactly once per user-driven dismissal;
// dialog tears itself down after firing. Raw pointer, caller-owned.
class IZUIDocSharePermissionDialogSink {
public:
  virtual ~IZUIDocSharePermissionDialogSink() = default;

  virtual void OnDocSharePermissionConfirmed(
      DocSharePermissionScope scope,
      DocSharePermissionLevel level,
      bool persistent_access_checked) {}
  virtual void OnDocSharePermissionCancelled() {}
};

class IZUIDocSharePermissionDialogMgr {
public:
  virtual ~IZUIDocSharePermissionDialogMgr() = default;

  virtual void SetSink(IZUIDocSharePermissionDialogSink* sink) = 0;

  // Windows entry. `parent` is an HWND; nullptr falls back to the popup's
  // needRootOwner resolution. Each call creates a fresh popup; Hide()
  // tears it down. No-op on macOS (host drives its NSWindow itself).
  virtual void Show(const DocSharePermissionConfig& config,
                    void* parent = nullptr) = 0;
  virtual void Hide() = 0;
  virtual bool IsVisible() = 0;

  // macOS embedded host attaches this View; returns nullptr on Windows.
  virtual std::shared_ptr<zui::View> GetContentView() = 0;
};

#endif  // ZUI_DOC_SHARE_PERMISSION_DIALOG_IT_H_
