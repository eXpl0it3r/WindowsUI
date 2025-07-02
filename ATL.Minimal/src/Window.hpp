#pragma once

#include <atlbase.h>
#include <atlwin.h>
#include <ATLControls.h>

enum {
    IDC_BUTTON = 202
};

class Window : public ATL::CWindowImpl<Window, ATL::CWindow, ATL::CWinTraits<WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX>>
{
public:
    DECLARE_WND_CLASS(L"ATL.Minimal")

    ATL::CStatic m_label;
    //WTL::CButton m_button;

    BEGIN_MSG_MAP(Window)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_CLOSE, OnClose)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
        COMMAND_ID_HANDLER(IDC_BUTTON, OnButtonClick)
    END_MSG_MAP()

    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnButtonClick(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
};
