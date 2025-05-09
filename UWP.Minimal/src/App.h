#pragma once
#include "pch.h"

namespace UWP_Minimal
{
    struct App : winrt::Windows::UI::Xaml::ApplicationT<App>
    {
        App();
        
        void OnLaunched(winrt::Windows::ApplicationModel::Activation::LaunchActivatedEventArgs const& args);
        void OnSuspending(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::ApplicationModel::SuspendingEventArgs const& args);
    };
}