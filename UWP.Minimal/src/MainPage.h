#pragma once

#include "pch.h"

namespace winrt::UWP_Minimal::implementation
{
    struct MainPage : Windows::UI::Xaml::Controls::PageT<MainPage>
    {
        MainPage();

        void OnButtonClick(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    
    private:
        Windows::UI::Xaml::Controls::TextBlock m_label{ nullptr };
        Windows::UI::Xaml::Controls::Button m_button{ nullptr };
    };
}

namespace UWP_Minimal
{
    // Use this alias in XAML files to reference the implementation
    using MainPage = winrt::UWP_Minimal::implementation::MainPage;
}