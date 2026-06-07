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
WiX_EditFrame::WiX_EditFrame():wxFrame(nullptr,wxID_ANY,"WiX_Edit",wxDefaultPosition,wxSize(1200,800))
{
    ///初始化Aui管理器
    Menus.push_back(new wxMenu());
    Menus[0]->Append(wxID_NEW,L"New\tCtrl+N");
    Menus[0]->AppendSeparator();
    Menus[0]->Append(wxID_OPEN,L"Open\tCtrl+O");
    Menus[0]->Append(wxID_SAVE,L"Save\tCtrl+S");
    Menus[0]->Append(wxID_SAVEAS,L"Save as\tCtrl+Alt+S");
    Menus[0]->AppendSeparator();
    Menus[0]->Append(wxID_EXIT,L"Quit\tCtrl+X");
    Menu->Append(Menus[0],L"&File");
    Menus.push_back(new wxMenu());
    Menus[1]->Append(wxID_ABOUT,L"About\tCtrl+A");
    Menu->Append(Menus[1],L"&Help");
    Bind(wxEVT_MENU,&OnQuit,this,wxID_EXIT);
    Bind(wxEVT_MENU,&ShowAbout,this,wxID_ABOUT);
    SetMenuBar(Menu);
    WiX_Edit_Mgr.SetManagedWindow(this);
    WiX_Edit_Mgr.SetFlags(wxAUI_MGR_DEFAULT);
    ///设置编辑器属性
    Editor->SetKeyWords(0,
            "Wix Product Package MajorUpgrade MediaTemplate Media "
            "Directory DirectoryRef File Component ComponentRef ComponentGroup ComponentGroupRef "
            "Feature FeatureRef FeatureGroup FeatureGroupRef "
            "CustomAction CustomTable Binary Icon "
            "Property PropertyRef RegistrySearch "
            "Condition LaunchCondition "
            "UI Dialog DialogRef UIRef "
            "Shortcut RemoveFolder "
            "ServiceInstall ServiceControl "
            "Upgrade UpgradeVersion "
            "Fragment FragmentRef "
            "Bundle Chain PackageGroup PackageGroupRef "
            "Variable MsiProperty "
            "Payload PayloadGroup "
            "Chain Chain "
            "Log LogVariable "
            "BootstrapperApplicationRef "
            "WixVariable "
            "Bundle Variable "
            "Payload PayloadGroup");
    Editor->SetKeyWords(1,
            "Id Name Version Manufacturer Language Codepage "
            "InstallerVersion Compressed InstallScope "
            "UpgradeCode Description "
            "Source DiskId KeyPath Vital "
            "Condition Level Display ConfigurableDirectory "
            "Feature Feature_ "
            "Action ExeCommand Execute Return Check "
            "Value Secure Hidden System "
            "Dialog Title Width Height "
            "Target TargetDir WorkingDirectory ShowCmd "
            "Name Arguments Description Hotkey Icon IconIndex "
            "Start Auto Stop Wait Remove Uninstall "
            "Minimum Maximum IncludeMinimum IncludeMaximum OnlyDetect "
            "IgnoreRemoveFailure Permanent DisallowRemoval "
            "SuppressLooseFiles SuppressIces "
            "InstallCondition UninstallCondition "
            "After Before Sequence "
            "Patch AllowIgnoreOnError Vital "
            "Directory DisplayName Description Manufacturer "
            "Protocol Protocol_ "
            "Advertise Attributes");
    Editor->SetKeyWords(2,
            "xml version encoding standalone "
            "xmlns xsi schemaLocation "
            "id class style href src alt title "
            "width height border cellpadding cellspacing "
            "colspan rowspan align valign "
            "type name value checked disabled readonly "
            "method action enctype "
            "rel target media charset "
            "lang dir accesskey tabindex "
            "onclick onchange onload onsubmit "
            "style class");
    Editor->Bind(wxEVT_STC_CHARADDED,&OnChar,this);
    Editor->AutoCompSetSeparator(' ');
    Editor->AutoCompSetMaxHeight(15);
    Editor->SetWrapMode(wxSTC_WRAP_NONE);
    Editor->SetIndentationGuides(true);
    Editor->SetBackSpaceUnIndents(true);
    Editor->SetTabIndents(true);
    Editor->SetTabWidth(4);
    Editor->SetUseTabs(false);
    Editor->SetViewWhiteSpace(wxSTC_WS_INVISIBLE);
    Editor->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    Editor->SetMarginWidth(0, 50);
    Editor->SetMarginType(1, wxSTC_MARGIN_SYMBOL);
    Editor->SetMarginWidth(1, 16);
    Editor->SetMarginMask(1, wxSTC_MASK_FOLDERS);
    Editor->SetMarginSensitive(1, true);
    Editor->SetProperty("fold", "1");
    Editor->SetProperty("fold.html", "1");
    Editor->SetProperty("fold.compact", "1");
    Editor->SetFoldFlags(wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);
    Editor->SetLexer(wxSTC_LEX_HTML);
    Editor->StyleSetForeground(wxSTC_STYLE_DEFAULT, wxColour(0, 0, 0));
    Editor->StyleSetBackground(wxSTC_STYLE_DEFAULT, wxColour(255, 255, 255));
    Editor->StyleSetForeground(wxSTC_H_TAG, wxColour(0, 0, 255));
    Editor->StyleSetBold(wxSTC_H_TAG, true);
    Editor->StyleSetForeground(wxSTC_H_ATTRIBUTE, wxColour(255, 0, 0));
    Editor->StyleSetForeground(wxSTC_H_VALUE, wxColour(0, 125, 0));
    Editor->StyleSetForeground(wxSTC_H_COMMENT, wxColour(128, 128, 128));
    Editor->StyleSetItalic(wxSTC_H_COMMENT, true);
    Editor->StyleSetForeground(wxSTC_H_ENTITY, wxColour(255, 128, 0));
    Editor->StyleSetForeground(wxSTC_H_CDATA, wxColour(128, 0, 128));
    Editor->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(128, 128, 128));
    Editor->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(240, 240, 240));
    Editor->StyleSetForeground(wxSTC_H_DOUBLESTRING, wxColour(0, 125, 0));
    Editor->StyleSetForeground(wxSTC_H_SINGLESTRING, wxColour(0, 125, 0));
    Editor->SetIndent(4);
    Editor->SetTabWidth(4);
    Editor->SetUseTabs(false);
    Editor->StyleSetForeground(wxSTC_STYLE_BRACELIGHT, wxColour(255, 0, 0));
    Editor->StyleSetBackground(wxSTC_STYLE_BRACELIGHT, wxColour(255, 255, 0));
    Editor->SetSelForeground(true, wxColour(255, 255, 255));
    Editor->SetSelBackground(true, wxColour(0, 0, 255));
    Editor->SetCaretForeground(wxColour(0, 0, 0));
    ///添加面板
    WiX_Edit_Mgr.AddPane(Editor,wxAuiPaneInfo().CenterPane().Name(wxString(L"Editor")));
    WiX_Edit_Mgr.AddPane(FileList,wxAuiPaneInfo().Left().Caption(L"Files").Name(L"File").BestSize(wxSize(300,800)));
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
/**
 \brief 绑定编辑器的输入事件
 \return 无
*/
void WiX_EditFrame::OnChar(wxStyledTextEvent& event)
{
    char key = event.GetKey();
    wxStyledTextCtrl* ed = dynamic_cast<wxStyledTextCtrl*>(event.GetEventObject());
    if (!ed) {
        event.Skip();
        return;
    }
    int currentPos = ed->GetCurrentPos();
    int start, end;
    bool p = false;
    ed->GetSelection(&start, &end);
    // ---------- 处理 < 键 ----------
    if (key == '<') {
        p = true;
        if (start != end) {
            wxString selectedText = ed->GetTextRange(start, end);
            ed->ReplaceSelection(wxString::Format("<%s>", selectedText));
            ed->SetSelection(start + 1, start + 1 + selectedText.length());
        } else {
            ed->InsertText(currentPos, ">");
            ed->SetSelection(currentPos, currentPos);
        }
        ed->AutoCompShow(0,
            "Wix Product Package MajorUpgrade MediaTemplate Media "
            "Directory DirectoryRef File Component ComponentRef ComponentGroup ComponentGroupRef "
            "Feature FeatureRef FeatureGroup FeatureGroupRef "
            "CustomAction CustomTable Binary Icon "
            "Property PropertyRef RegistrySearch "
            "Condition LaunchCondition "
            "UI Dialog DialogRef UIRef "
            "Shortcut RemoveFolder "
            "ServiceInstall ServiceControl "
            "Upgrade UpgradeVersion "
            "Fragment FragmentRef "
            "Bundle Chain PackageGroup PackageGroupRef "
            "Variable MsiProperty "
            "Payload PayloadGroup "
            "Chain Chain "
            "Log LogVariable "
            "BootstrapperApplicationRef "
            "WixVariable "
            "Bundle Variable "
            "Payload PayloadGroup");
        return;
    }
    // ---------- 处理 / 键（插入斜杠，闭合标签补全）----------
    else if (key == '/') {
        p = true;
        if (start != end) {
            wxString selectedText = ed->GetTextRange(start, end);
            ed->ReplaceSelection(wxString::Format("<%s>", selectedText));
            ed->SetSelection(start + 1, start + 1 + selectedText.length());
        }
        ed->AutoCompShow(0,
            "Wix Product Package MajorUpgrade MediaTemplate Media "
            "Directory DirectoryRef File Component ComponentRef ComponentGroup ComponentGroupRef "
            "Feature FeatureRef FeatureGroup FeatureGroupRef "
            "CustomAction CustomTable Binary Icon "
            "Property PropertyRef RegistrySearch "
            "Condition LaunchCondition "
            "UI Dialog DialogRef UIRef "
            "Shortcut RemoveFolder "
            "ServiceInstall ServiceControl "
            "Upgrade UpgradeVersion "
            "Fragment FragmentRef "
            "Bundle Chain PackageGroup PackageGroupRef "
            "Variable MsiProperty "
            "Payload PayloadGroup "
            "Chain Chain "
            "Log LogVariable "
            "BootstrapperApplicationRef "
            "WixVariable "
            "Bundle Variable "
            "Payload PayloadGroup");
        return;
    }
    // ---------- 处理单引号、双引号、空格（保持原逻辑）----------
    else if (key == '\'') {
        p = true;
        if (start != end) {
            wxString selectedText = ed->GetTextRange(start, end);
            ed->ReplaceSelection(wxString::Format("'%s'", selectedText));
            ed->SetSelection(start + 1, start + 1 + selectedText.length());
        } else {
            ed->InsertText(currentPos, "'");
            ed->SetSelection(currentPos, currentPos);
        }
        ed->AutoCompShow(0,
            "yes no true false perMachine perUser immediate deferred commit rollback "
            "check ignore auto demand disabled normal minimized maximized * PUT-GUID-HERE "
            "1.0.0.0 2.0.0.0 1033 2052 TARGETDIR ProgramFilesFolder INSTALLFOLDER C:\\ D:\\ ");
        return;
    }
    else if (key == '"') {
        p = true;
        if (start != end) {
            wxString selectedText = ed->GetTextRange(start, end);
            ed->ReplaceSelection(wxString::Format("\"%s\"", selectedText));
            ed->SetSelection(start + 1, start + 1 + selectedText.length());
        } else {
            ed->InsertText(currentPos, "\"");
            ed->SetSelection(currentPos, currentPos);
        }
        ed->AutoCompShow(0,
            "yes no true false perMachine perUser immediate deferred commit rollback "
            "check ignore auto demand disabled normal minimized maximized * PUT-GUID-HERE "
            "1.0.0.0 2.0.0.0 1033 2052 TARGETDIR ProgramFilesFolder INSTALLFOLDER C:\\ D:\\ ");
        return;
    }
    else if (key == ' ') {
        p = true;
        int pos = ed->GetCurrentPos();
        bool inTag = false;
        for (int i = pos - 1; i >= 0; --i) {
            wxChar ch = ed->GetCharAt(i);
            if (ch == '>') break;
            if (ch == '<') { inTag = true; break; }
            if (ch == '\n') break;
        }
        if (inTag) {
            ed->AutoCompShow(0,
                "Id Name Version Manufacturer Language Codepage InstallerVersion Compressed InstallScope "
                "UpgradeCode Description Source DiskId KeyPath Vital Condition Level Display ConfigurableDirectory "
                "Feature Feature_ Action ExeCommand Execute Return Check Value Secure Hidden System "
                "Dialog Title Width Height Target TargetDir WorkingDirectory ShowCmd Name Arguments Description "
                "Hotkey Icon IconIndex Start Auto Stop Wait Remove Uninstall Minimum Maximum IncludeMinimum "
                "IncludeMaximum OnlyDetect IgnoreRemoveFailure Permanent DisallowRemoval SuppressLooseFiles "
                "SuppressIces InstallCondition UninstallCondition After Before Sequence Patch AllowIgnoreOnError "
                "Vital Directory DisplayName Description Manufacturer Protocol Protocol_ Advertise Attributes");
        }
        return;
    }

    // 其他按键交给默认处理
    if (!p) {
        event.Skip();
    }
}
/**
 \brief 展示关于对话框
 \note 对话框使用栈
*/
void WiX_EditFrame::ShowAbout(wxCommandEvent& event){
    AboutDlg Dlg(this);
    Dlg.ShowModal();
}
/**
 \brief "关于"对话框的构造函数实现
 \note 实现一些文本以及一个按钮
*/
AboutDlg::AboutDlg(WiX_EditFrame* WND):wxDialog(WND,wxID_ANY,L"About",wxDefaultPosition,wxSize(300,200)){
    OK_Key=new wxButton(this,wxID_OK,L"OK");
    DlgSizer->Add(new wxStaticText(this,wxID_ANY,L"WiX_Edit"),0,wxALIGN_CENTER|wxALL,5);
    DlgSizer->Add(new wxStaticText(this,wxID_ANY,L"Author:(C)asd-85110"),0,wxALIGN_CENTER|wxALL,5);
    DlgSizer->Add(new wxStaticText(this,wxID_ANY,wxString::Format(L"Version:%s",VERSION)),0,wxALIGN_CENTER|wxALL,5);
    DlgSizer->Add(new wxStaticText(this,wxID_ANY,L"LICENSE:Mozilla Public License v2.0"),0,wxALIGN_CENTER|wxALL,5);
    DlgSizer->Add(OK_Key,0,wxALIGN_CENTER|wxALL,5);
    Bind(wxEVT_BUTTON,&Ok_Click,this,wxID_OK);
    SetSizer(DlgSizer);
    DlgSizer->SetSizeHints(this);
}
/**
 \brief 处理按下OK的按钮事件
 \note 使用wxCommandEvent
*/
void AboutDlg::Ok_Click(wxCommandEvent& event){
    EndModal(wxID_OK);
}
///\brief 退出事件实现
void WiX_EditFrame::OnQuit(wxCommandEvent& event){
    Close(true);
}
