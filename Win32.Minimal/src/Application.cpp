#include "Application.hpp"

#include <CommCtrl.h>

Application::Application()
{
    const auto* ClassName = L"Win32.Minimal";

    auto windowClass = WNDCLASS{};
    windowClass.lpfnWndProc = &Application::HandleEventGlobally;
    windowClass.hInstance = GetModuleHandle(nullptr);
    windowClass.lpszClassName = ClassName;
    windowClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&windowClass);

    m_window = CreateWindowEx(0, ClassName, L"Win32 Minimal", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, nullptr, nullptr, nullptr, this);
    m_label = CreateWindowEx(0, WC_STATIC, L"Hello World!", WS_CHILD | WS_VISIBLE | SS_CENTER, 50, 50, 200, 50, m_window, nullptr, nullptr, nullptr);
    m_button = CreateWindowEx(0, WC_BUTTON, L"DO NOT TOUCH", WS_CHILD | WS_VISIBLE, 75, 150, 150, 25, m_window, nullptr, nullptr, nullptr);
}

void Application::Run()
{
    ShowWindow(m_window, SW_SHOW);

    for (auto message = MSG{0}; GetMessage(&message, nullptr, 0, 0);)
    {
        DispatchMessage(&message);
    }
}

LRESULT CALLBACK Application::HandleEventGlobally(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    // Set the application instance on window creation
    if (message == WM_CREATE)
    {
        auto app = reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
        SetWindowLongPtr(handle, GWLP_USERDATA, app);
    }

    // Extract the application instance
    auto* app = handle ? reinterpret_cast<Application*>(GetWindowLongPtr(handle, GWLP_USERDATA)) : nullptr;

    if (app)
    {
        app->HandleEvent(message, wParam, lParam);
    }

    return DefWindowProcW(handle, message, wParam, lParam);
}

void Application::HandleEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CLOSE:
        OnWindowClose();
        break;
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED && reinterpret_cast<HWND>(lParam) == m_button)
        {
            OnButtonClick();
        }
        break;
    default:
        break;
    }
}

void Application::OnWindowClose()
{
    PostQuitMessage(0);
}

void Application::OnButtonClick()
{
    SendMessage(m_label, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(L"Don't touch that!"));
}