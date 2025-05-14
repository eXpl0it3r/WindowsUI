#pragma once

#include <atlbase.h>
#include <atlapp.h>
#include <atlctrls.h>
#include <atlframe.h>
#include <atlcrack.h>
#include <atlmisc.h>
#include <atlgdi.h>

enum {
    IDC_BUTTON = 202,
    IDR_MAINFRAME = 1001
};

class Window : public WTL::CFrameWindowImpl<Window>
{
public:
    DECLARE_FRAME_WND_CLASS(L"WTL.Minimal", IDR_MAINFRAME)

    WTL::CStatic m_label;
    WTL::CButton m_button;

    BEGIN_MSG_MAP_EX(Window)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_CLOSE(OnClose)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_ERASEBKGND(OnEraseBkgnd)
        COMMAND_ID_HANDLER_EX(IDC_BUTTON, OnButtonClick)
        CHAIN_MSG_MAP(WTL::CFrameWindowImpl<Window>)
    END_MSG_MAP()

    LRESULT OnCreate(LPCREATESTRUCT lpcs);
    void OnClose();
    void OnDestroy();
    LRESULT OnEraseBkgnd(HDC hdc);
    void OnButtonClick(UINT uCode, int nID, HWND hwncCtrl);
};
