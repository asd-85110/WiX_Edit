/***************************************************************
 * Name:      WiX_EditApp.hpp
 * Purpose:   Defines Application Class
 * Author:    Github:asd-85110 (1703115048@qq.com)
 * Created:   2026-05-09
 * Copyright: Github:asd-85110 (https://github.com/asd-85110)
 * License: Mozilla Public License v2.0
 **************************************************************/

#ifndef WIX_EDITAPP_H
#define WIX_EDITAPP_H

#include <wx/app.h>
#include <wx/xml/xml.h>
///\brief 定义了WiX_EditApp类
///有成员函数Oninit
class WiX_EditApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WIX_EDITAPP_H
