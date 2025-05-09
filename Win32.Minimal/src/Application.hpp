#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

class Application
{
    HWND m_window = nullptr;
    HWND m_button = nullptr;
    HWND m_label = nullptr;

public:
    Application();
    void Run();

private:
    static LRESULT CALLBACK HandleEventGlobally(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);
    void HandleEvent(UINT message, WPARAM wParam, LPARAM lParam);

    void OnWindowClose();
    void OnButtonClick();
};