#include "App.h"

using namespace winrt;
using namespace Windows::UI::Xaml::Hosting;

namespace XamlIslands
{
    App& App::Instance()
    {
        static App instance;
        return instance;
    }

    void App::Initialize()
    {
        // Initialize XAML framework for the Win32 application
        m_xamlManager = WindowsXamlManager::InitializeForCurrentThread();
        m_xamlSource = DesktopWindowXamlSource{};
    }

    void App::Shutdown()
    {
        // Clean up XAML resources
        if (m_xamlSource)
        {
            m_xamlSource.Close();
            m_xamlSource = nullptr;
        }

        if (m_xamlManager)
        {
            m_xamlManager.Close();
            m_xamlManager = nullptr;
        }
    }
}