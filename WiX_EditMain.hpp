/***************************************************************
 * Name:      WiX_EditMain.hpp
 * Purpose:   Defines Application Frame
 * Author:    Github:asd-85110 (1703115048@qq.com)
 * Created:   2026-05-09
 * Copyright: Github:asd-85110 (https://github.com/asd-85110)
 * License: Mozilla Public License v2.0
 **************************************************************/

#ifndef WIX_EDITMAIN_H
#define WIX_EDITMAIN_H

#ifndef WX_PRECOMP
/**
 \brief 这里是一些必要的头文件
 \brief wx.h是wxWidgets的核心头文件
 \brief stc/stc.h用于代码编辑
 \brief webview.h渲染网页
 \brief aui/aui.h使用高级用户界面
*/
    #include <wx/wx.h>
    #include <wx/stc/stc.h>
    #include <wx/webview.h>
    #include <wx/aui/aui.h>
#endif

#include "WiX_EditApp.hpp"
///\brief 主窗口类
class WiX_EditFrame: public wxFrame
{
    public:
        WiX_EditFrame();
        ~WiX_EditFrame();
    private:
        wxAuiManager WiX_Edit_Mgr;
        wxStyledTextCtrl* Editor=new wxStyledTextCtrl(this,wxID_ANY);
};


#endif // WIX_EDITMAIN_H
