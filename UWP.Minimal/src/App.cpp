#include "pch.h"
#include "App.h"
#include "MainPage.h"

using namespace winrt;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

namespace winrt::UWP_Minimal::implementation
{
    // Application entry point
    int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
    {
        Application::Start([](auto&) {
            winrt::make<UWP_Minimal::App>();
        });
        return 0;
    }
}

namespace UWP_Minimal
{
    App::App()
    {
        Suspending({ this, &App::OnSuspending });

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
        UnhandledException([](IInspectable const&, UnhandledExceptionEventArgs const& e)
        {
            if (IsDebuggerPresent())
            {
                auto errorMessage = e.Message();
                __debugbreak();
            }
        });
#endif
    }

    void App::OnLaunched(LaunchActivatedEventArgs const& e)
    {
        if (auto window = Window::Current())
        {
            window.Title(L"UWP Minimal");
            
            Frame rootFrame{ nullptr };
            auto content = window.Content();
            if (content)
            {
                rootFrame = content.try_as<Frame>();
            }

            if (rootFrame == nullptr)
            {
                rootFrame = Frame();
                rootFrame.NavigationFailed({ this, &App::OnNavigationFailed });
                window.Content(rootFrame);
            }

            if (rootFrame.Content() == nullptr)
            {
                rootFrame.Navigate(xaml_typename<UWP_Minimal::MainPage>());
            }

            window.Activate();
        }
    }

    void App::OnSuspending(IInspectable const&, SuspendingEventArgs const&)
    {
        // Save application state and stop any background activity
    }

    void App::OnNavigationFailed(IInspectable const&, NavigationFailedEventArgs const& e)
    {
        throw hresult_error(E_FAIL, hstring(L"Failed to load Page ") + e.SourcePageType().Name);
    }
}