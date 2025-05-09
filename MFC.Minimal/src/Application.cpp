#include "Application.hpp"

#include "Window.hpp"

// Globally constructed application object
Application app;

BOOL Application::InitInstance()
{
    // Will be cleaned up by MFC
    m_pMainWnd = new Window{};

    m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}