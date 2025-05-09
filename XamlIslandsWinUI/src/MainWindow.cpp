#include "MainWindow.h"
#include "App.h"

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <Windows.UI.Xaml.Hosting.DesktopWindowXamlSource.h>

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Hosting;
using namespace Windows::Foundation;

namespace XamlIslands
{
    MainWindow::MainWindow()
    {
    }

    MainWindow::~MainWindow()
    {
        App::Instance().Shutdown();
        if (m_hwnd)
        {
            DestroyWindow(m_hwnd);
            m_hwnd = nullptr;
        }
    }

    bool MainWindow::Initialize()
    {
        // Register the window class
        const wchar_t* CLASS_NAME = L"XAML_ISLANDS_WINDOW";
        
        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpszClassName = CLASS_NAME;
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        
        RegisterClass(&wc);
        
        // Create the window
        m_hwnd = CreateWindowEx(
            0,                      // Optional window styles
            CLASS_NAME,             // Window class
            L"XAML Islands Minimal",// Window text
            WS_OVERLAPPEDWINDOW,    // Window style
            
            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, 300, 300,
            
            nullptr,                // Parent window
            nullptr,                // Menu
            GetModuleHandle(nullptr),// Instance handle
            this                    // Additional application data
        );
        
        if (!m_hwnd)
        {
            return false;
        }
        
        // Initialize XAML infrastructure
        App::Instance().Initialize();
        
        // Create and initialize the XAML Island
        auto& xamlSource = App::Instance().GetXamlSource();
        
        // Get the XAML source's window handle and parent it to main window
        auto interopObject = xamlSource.as<IDesktopWindowXamlSourceNative>();
        check_hresult(interopObject->AttachToWindow(m_hwnd));
        
        // Get the HWND of the XAML child window
        check_hresult(interopObject->get_WindowHandle(&m_xamlIslandHwnd));
        
        // Place the XAML island within our window
        SetWindowPos(m_xamlIslandHwnd, nullptr, 0, 0, 300, 300, SWP_SHOWWINDOW);
        
        // Initialize the XAML content
        InitializeXamlContent();
        
        return true;
    }

    void MainWindow::Run()
    {
        ShowWindow(m_hwnd, SW_SHOW);
        
        // Message loop
        MSG msg = {};
        while (GetMessage(&msg, nullptr, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void MainWindow::InitializeXamlContent()
    {
        // Get the XAML source
        auto& xamlSource = App::Instance().GetXamlSource();
        
        // Create root layout panel
        m_rootPanel = StackPanel();
        m_rootPanel.VerticalAlignment(VerticalAlignment::Center);
        m_rootPanel.HorizontalAlignment(HorizontalAlignment::Center);
        
        // Create the text label
        m_label = TextBlock();
        m_label.Text(L"Hello World!");
        m_label.FontSize(24);
        m_label.TextAlignment(TextAlignment::Center);
        m_label.Margin(Thickness{ 0, 0, 0, 50 });
        
        // Create the button
        m_button = Button();
        m_button.Content(box_value(L"DO NOT TOUCH"));
        m_button.HorizontalAlignment(HorizontalAlignment::Center);
        
        // Add click handler to the button
        m_button.Click([this](IInspectable const&, RoutedEventArgs const&) {
            OnButtonClick();
        });
        
        // Add controls to the panel
        m_rootPanel.Children().Append(m_label);
        m_rootPanel.Children().Append(m_button);
        
        // Set the panel as the XAML content
        xamlSource.Content(m_rootPanel);
    }

    void MainWindow::OnButtonClick()
    {
        // Change the label text when the button is clicked
        m_label.Text(L"Don't touch that!");
    }

    LRESULT CALLBACK MainWindow::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        MainWindow* window = nullptr;
        
        if (message == WM_CREATE)
        {
            auto pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
            window = reinterpret_cast<MainWindow*>(pCreate->lpCreateParams);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
        }
        else
        {
            window = reinterpret_cast<MainWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        }
        
        if (window)
        {
            return window->HandleMessage(message, wParam, lParam);
        }
        
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    LRESULT MainWindow::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
            
        case WM_SIZE:
            if (m_xamlIslandHwnd)
            {
                // Resize the XAML Island when the parent window is resized
                RECT parentRect;
                GetClientRect(m_hwnd, &parentRect);
                SetWindowPos(m_xamlIslandHwnd, nullptr, 0, 0, 
                            parentRect.right - parentRect.left,
                            parentRect.bottom - parentRect.top,
                            SWP_SHOWWINDOW);
            }
            return 0;
            
        default:
            return DefWindowProc(m_hwnd, message, wParam, lParam);
        }
    }
}