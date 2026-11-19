#ifndef I_FEEDBACK_DIALOG_MGR_H
#define I_FEEDBACK_DIALOG_MGR_H

#include "zUI_stdafx.h"
#include <string>

struct FeedbackInformation;

// Carries the selected reasons + optional comment from the bad-experience form.
struct BadExperienceFeedback {
  bool cannot_hear_others  = false;  // "I could not hear others"  (reason 9)
  bool cannot_see_others   = false;  // "I could not see others"   (reason 11)
  bool others_cannot_hear  = false;  // "Others could not hear me" (reason 8)
  bool others_cannot_see   = false;  // "Others could not see me"  (reason 10)
  bool poor_audio          = false;  // "Poor audio quality"       (reason 2)
  bool poor_video          = false;  // "Poor video quality"       (reason 1)
  std::string additional_comments;
};

// Manages the lifetime of the ZUI feedback dialog (UberLike thumbs up/down)
// and its bad-experience follow-up dialog. Replaces CFeedbackWnd /
// CBadExperienceWnd. Lives in PTMgrHub alongside ILeaveMsgDialogMgr.
class ZUIClient_API IFeedbackDialogMgr
{
public:
  virtual ~IFeedbackDialogMgr() {}

  virtual void Init() = 0;
  virtual void Uninit() = 0;

  // Show the ZUI feedback (👍/👎) dialog.
  // PAAP tracking and SendFeedback API calls are handled internally by the Mgr.
  virtual void ShowFeedbackDialog(const FeedbackInformation& info) = 0;
  virtual void DismissFeedbackDialog() = 0;
  virtual bool IsFeedbackDialogShowing() const = 0;
  virtual void BringFeedbackDialogToTop() = 0;

  // Show the bad-experience follow-up dialog (replaces CBadExperienceWnd).
  // Positions the new window at the same screen location as the feedback dialog.
  virtual void ShowBadExperience(const FeedbackInformation& info) = 0;
  virtual void DismissBadExperience() = 0;
  virtual bool IsBadExperienceShowing() const = 0;
};

#endif  // I_FEEDBACK_DIALOG_MGR_H
