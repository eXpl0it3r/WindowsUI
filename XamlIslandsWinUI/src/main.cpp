#include <windows.h>
#include <winrt/base.h>
#include "MainWindow.h"

// Entry point for the application
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Initialize Windows Runtime
    winrt::init_apartment();
    
    // Create the main window
    XamlIslands::MainWindow mainWindow;
    
    // Initialize and run the window
    if (mainWindow.Initialize())
    {
        mainWindow.Run();
    }
    
    // Uninitialize Windows Runtime
    winrt::uninit_apartment();
    
    return 0;
}