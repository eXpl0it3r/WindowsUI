#include "pch.h"
#include "MainPage.h"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

namespace winrt::UWP_Minimal::implementation
{
    MainPage::MainPage()
    {
        // This will be called after the XAML is loaded and parsed
        Loaded([this](IInspectable const& sender, RoutedEventArgs const& args)
        {
            // Get references to the XAML elements by name
            m_label = FindName(L"HelloLabel").as<TextBlock>();
            m_button = FindName(L"DoNotTouchButton").as<Button>();
        });
    }

    void MainPage::OnButtonClick(IInspectable const&, RoutedEventArgs const&)
    {
        // Change the label text when the button is clicked, just like in the Win32 app
        m_label.Text(L"Don't touch that!");
    }
}