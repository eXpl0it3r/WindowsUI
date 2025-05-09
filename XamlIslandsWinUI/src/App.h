#pragma once

#include <windows.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Xaml.Controls.h>

namespace XamlIslands
{
    class App
    {
    public:
        static App& Instance();
        
        void Initialize();
        void Shutdown();
        
        winrt::Windows::UI::Xaml::Hosting::DesktopWindowXamlSource& GetXamlSource() { return m_xamlSource; }
        
    private:
        App() = default;
        ~App() = default;
        
        winrt::Windows::UI::Xaml::Hosting::WindowsXamlManager m_xamlManager{ nullptr };
        winrt::Windows::UI::Xaml::Hosting::DesktopWindowXamlSource m_xamlSource{ nullptr };
    };
}