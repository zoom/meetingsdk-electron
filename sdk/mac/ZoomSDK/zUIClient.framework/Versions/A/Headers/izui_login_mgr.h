#ifndef ZUI_LOGIN_IT_H_
#define ZUI_LOGIN_IT_H_

//#include "zui_base.h"
#include "zUI_stdafx.h"
#include "zUI/view.h"

///**
// * @brief Callback interface for login UI events
// */
class ZUIClient_API IZUILoginSink
{
public:
    virtual ~IZUILoginSink() = default;

    /**
     * @brief Called when user clicks Sign In button
     */
    virtual void OnSignInClick() = 0;

    /**
     * @brief Called when user clicks Sign Up button
     */
    virtual void OnSignUpClick() = 0;

    // Future extensible callbacks:
    // virtual void OnOtherButtonClick() = 0;
};

class ZUIClient_API IZUILoginTabsIntroductionMgr
{
public:
    virtual ~IZUILoginTabsIntroductionMgr() = default;

    virtual void onCurrentTabChange(const std::string& tabIdentifier) = 0;
    virtual std::shared_ptr<zui::View> GetView() = 0;
    virtual void RemoveView() = 0;
};

/**
 * @brief Manager interface for login tabs introduction view
 */
class ZUIClient_API IZUILoginMgr
{
public:
    virtual ~IZUILoginMgr() = default;

    //setSink
    virtual void SetSink(IZUILoginSink* sink) = 0;

    //getSink
    virtual IZUILoginSink* GetSink() = 0;

    /**
     * @brief Get login tabs introduction view
     * @return Embeddable View object
     */
    virtual IZUILoginTabsIntroductionMgr* GetLoginTabsIntroductionMgr() = 0;
};

#endif // ZUI_LOGIN_IT_H_

