#pragma once
#include <windows.h>
#include <winrt/Windows.UI.Xaml.Controls.h>

namespace XamlIslands
{
    class MainWindow
    {
    public:
        MainWindow();
        ~MainWindow();
        
        bool Initialize();
        void Run();
        
    private:
        void InitializeXamlContent();
        void OnButtonClick();
        
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
        LRESULT HandleMessage(UINT message, WPARAM wParam, LPARAM lParam);

    private:
        HWND m_hwnd = nullptr;
        HWND m_xamlIslandHwnd = nullptr;
        
        // XAML controls
        winrt::Windows::UI::Xaml::Controls::StackPanel m_rootPanel{ nullptr };
        winrt::Windows::UI::Xaml::Controls::TextBlock m_label{ nullptr };
        winrt::Windows::UI::Xaml::Controls::Button m_button{ nullptr };
    };
}