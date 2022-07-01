#include <platform/win32/wm_win32_window.h>

typedef struct wm_native_window_t
{
    HWND window_handle;
    HINSTANCE instance;

    LPSTR window_class_name;

} WmNativeWindow;

internal WmNativeWindow win32_window = { 0 };

private LRESULT Win32WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
        case WM_DESTROY:
        case WM_QUIT:
            /// TODO: Implements window exit 
            break;
    }
}

private void Win32RegisterClass(const string name)
{
    WNDCLASSEXA window_class = { 0 };
    window_class.lpszClassName = name; 

    window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class.lpfnWndProc = Win32WndProc;
    window_class.hInstance = win32_window.instance;
    window_class.style = CS_VREDRAW | CS_HREDRAW;

    if (!RegisterClassExA(&window_class))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

internal void Win32CreateWindow(const WmWindowConfig* config)
{

}