/***************************************************************
 * Name:      WiX_EditMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Github:asd-85110 (1703115048@qq.com)
 * Created:   2026-05-09
 * Copyright: Github:asd-85110 (https://github.com/asd-85110)
 * License: Mozilla Public License v2.0
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#include "WiX_EditMain.hpp"
/**
 \brief 这里初始化了主窗口
 \return 无
*/
WiX_EditFrame::WiX_EditFrame():wxFrame(nullptr,wxID_ANY,"WiX_Edit",wxDefaultPosition,wxSize(600,400))
{
    ///初始化Aui管理器
    WiX_Edit_Mgr.SetManagedWindow(this);
    WiX_Edit_Mgr.SetFlags(wxAUI_MGR_DEFAULT);
    ///设置编辑器属性
    Editor->SetLexer(wxSTC_LEX_XML);
    Editor->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(75, 75, 75));
    Editor->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(220, 220, 220));
    Editor->StyleSetForeground(wxSTC_STYLE_DEFAULT, wxColour(255, 0, 0));
    Editor->StyleSetBackground(wxSTC_STYLE_DEFAULT, wxColour(255, 255, 255));
    ///添加面板
    WiX_Edit_Mgr.AddPane(Editor,wxAuiPaneInfo().CenterPane().Name(wxString(L"Editor")));
    WiX_Edit_Mgr.Update();
}
/**
 \brief 卸载了Aui管理器
 \return 无
*/
WiX_EditFrame::~WiX_EditFrame()
{
    WiX_Edit_Mgr.UnInit();
}
