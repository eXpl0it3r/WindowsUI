#include "Window.hpp"

LRESULT Window::OnCreate(LPCREATESTRUCT lpcs)
{
    auto labelRect = RECT{50, 50, 250, 100};
    m_label.Create(m_hWnd, &labelRect, L"Hello World!", WS_CHILD | WS_VISIBLE | SS_CENTER);
    auto buttonRect = RECT{75, 150, 225, 175};
    m_button.Create(m_hWnd, &buttonRect, L"DO NOT TOUCH", WS_CHILD | WS_VISIBLE, 0, IDC_BUTTON);

    return 0;
}

void Window::OnClose()
{
    DestroyWindow();
}

void Window::OnDestroy()
{
    PostQuitMessage(0);
}

void Window::OnButtonClick(UINT uCode, int nID, HWND hwndCtrl)
{
    if (nID == IDC_BUTTON)
    {
        m_label.SetWindowText(L"Don't touch that!");
    }
}

LRESULT Window::OnEraseBkgnd(HDC hdc)
{
    auto rect = CRect{};
    GetClientRect(rect);
    FillRect(hdc, &rect, (HBRUSH)(COLOR_BTNFACE + 1));
    
    return 1;
}