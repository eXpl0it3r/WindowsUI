#include "Application.hpp"

void Application::Run()
{
    if (m_window.Create(nullptr, CWindow::rcDefault, _T("ATL Minimal")) == nullptr || !m_window.IsWindow())
    {
        return;
    }

    m_window.SetWindowPos(nullptr, 0, 0, 300, 300, SWP_NOZORDER | SWP_NOMOVE);
    m_window.CenterWindow();
    m_window.ShowWindow(SW_SHOW);
    m_window.UpdateWindow();

    for (auto message = MSG{}; GetMessage(&message, NULL, 0, 0) > 0;)
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}