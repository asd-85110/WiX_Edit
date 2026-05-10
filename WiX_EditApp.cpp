/***************************************************************
 * Name:      WiX_EditApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Github:asd-85110 (1703115048@qq.com)
 * Created:   2026-05-09
 * Copyright: Github:asd-85110 (https://github.com/asd-85110)
 * License: Mozilla Public License v2.0
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#include "WiX_EditApp.hpp"
#include "WiX_EditMain.hpp"

wxIMPLEMENT_APP(WiX_EditApp);
/**
 \brief 这是Oninit的实现
 \return 返回true成功，false失败
*/
bool WiX_EditApp::OnInit()
{
    WiX_EditFrame* frame = new WiX_EditFrame();
    frame->SetIcon(wxICON("aaaa")); // To Set App Icon
    frame->Show();

    return true;
}
