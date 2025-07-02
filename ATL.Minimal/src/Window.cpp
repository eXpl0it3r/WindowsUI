#include "Window.hpp"

LRESULT Window::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    //auto labelRect = RECT{50, 50, 250, 100};
    //m_label.Create(m_hWnd, &labelRect, L"Hello World!", WS_CHILD | WS_VISIBLE | SS_CENTER);
    //auto buttonRect = RECT{75, 150, 225, 175};
    //m_button.Create(m_hWnd, &buttonRect, L"DO NOT TOUCH", WS_CHILD | WS_VISIBLE, 0, IDC_BUTTON);

    return 0;
}

LRESULT Window::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    DestroyWindow();
    return 0;
}

LRESULT Window::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    PostQuitMessage(0);
    return 0;
}

LRESULT Window::OnButtonClick(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    //if (nID == IDC_BUTTON)
    //{
    //    m_label.SetWindowText(L"Don't touch that!");
    //}
    return 0;
}

LRESULT Window::OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    auto deviceContext = reinterpret_cast<HDC>(wParam);
    auto rect = RECT{};
 
    GetClientRect(&rect);
    FillRect(deviceContext, &rect, reinterpret_cast<HBRUSH>(COLOR_BTNFACE + 1));
    
    return 1;
}