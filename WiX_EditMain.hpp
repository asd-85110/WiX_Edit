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
#define VERSION "1.0.0.1"
#ifndef WX_PRECOMP
/**
 \brief 这里是一些必要的头文件
 \brief wx.h是wxWidgets的核心头文件
 \brief stc/stc.h用于代码编辑
 \brief webview.h渲染网页
 \brief aui/aui.h使用高级用户界面
 \brief vector使用可变数组
*/
    #include <wx/wx.h>
    #include <wx/stc/stc.h>
    #include <wx/webview.h>
    #include <wx/aui/aui.h>
    #include <wx/treectrl.h>
    #include <vector>
#endif

#include "WiX_EditApp.hpp"
///\brief 主窗口类
class WiX_EditFrame: public wxFrame
{
    public:
        WiX_EditFrame();
        ~WiX_EditFrame();
    private:
        void OnChar(wxStyledTextEvent&);
        void OnQuit(wxCommandEvent&);
        void ShowAbout(wxCommandEvent&);
        wxAuiManager WiX_Edit_Mgr;
        wxStyledTextCtrl* Editor=new wxStyledTextCtrl(this,wxID_ANY);
        wxTreeCtrl* FileList=new wxTreeCtrl(this,wxID_ANY);
        wxMenuBar* Menu=new wxMenuBar();
        std::vector<wxMenu*> Menus;
        wxString FilePath;
};
///\brief 关于对话框类
class AboutDlg:public wxDialog
{
public:
    AboutDlg(WiX_EditFrame* WND);
    ~AboutDlg()=default;
private:
    void Ok_Click(wxCommandEvent&);
    wxBoxSizer* DlgSizer=new wxBoxSizer(wxVERTICAL);
    wxButton *OK_Key;
};
#endif // WIX_EDITMAIN_H
