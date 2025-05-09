#include "Window.hpp"
#include "Resource.hpp"

BEGIN_MESSAGE_MAP(Window, CFrameWnd)
    ON_WM_ERASEBKGND()
    ON_BN_CLICKED(IDB_BUTTON, &Window::OnButtonClicked)
END_MESSAGE_MAP()

Window::Window()
{
    Create(nullptr, _T("MFC Minimal"), WS_OVERLAPPEDWINDOW, CRect{0, 0, 300, 300});
    CenterWindow();

    m_label.Create(_T("Hello World!"), WS_CHILD | WS_VISIBLE | SS_CENTER, CRect{50, 50, 250, 100}, this, IDS_LABEL);
    m_button.Create(_T("DO NOT TOUCH"), WS_CHILD | WS_VISIBLE, CRect{75, 150, 225, 175}, this, IDB_BUTTON);
}

BOOL Window::OnEraseBkgnd(CDC* deviceContext)
{
    auto rect = CRect{};
    GetClientRect(&rect);
    
    auto* brush = CBrush::FromHandle((HBRUSH)(COLOR_BTNFACE + 1));
    deviceContext->FillRect(&rect, brush);
    
    return TRUE;
}

void Window::OnButtonClicked()
{
    m_label.SetWindowText(_T("Don't touch that!"));
}