//
//  zui_login_aic_view.hpp
//  zUIClient
//
//  Created by Davies Zhao on 2025/11/28.
//

#ifndef zui_login_aic_view_h
#define zui_login_aic_view_h

#if defined(__MACOS__) || defined(CMM_WIN)

#include <zUIClient/zui_client_include.h>

class ZUIClient_API ZUILoginAicView : public zui::CustomView<ZUILoginAicView>
{
public:
    ZUILoginAicView();
  virtual ~ZUILoginAicView();
  
  std::shared_ptr<zui::ViewNode> Build() override;
private:
    zui::View BuildAICHeaderView();
    zui::View BuildAICIntroductionView();
    zui::View BuildAICIntroductionItemView(std::string &string);
    zui::View BuildAICFooterView();
};

#endif // defined(__MACOS__) || defined(CMM_WIN)

#endif /* login_aic_view_h */
