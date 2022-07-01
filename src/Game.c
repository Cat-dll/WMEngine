#include <windows.h>

#include <deps/stb_image.h>

#include <stdint.h>

#define IsNotInvalidHandle(handle) handle.idx != INT16_MAX

static BOOL global_exit = FALSE;
static int64_t lines = 0;

static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_QUIT:
        case WM_CLOSE:
        case WM_DESTROY:
            global_exit = TRUE;
            break;
        default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

static uint64_t Trace(const char* msg)
{
    DWORD writes = 0;
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), msg, strlen(msg), &writes, NULL);

    CONSOLE_SCREEN_BUFFER_INFO info = { 0 };
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    info.dwCursorPosition.Y++;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), info.dwCursorPosition);

    return writes;
}

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
    WNDCLASS wndClass = { 0 };
    wndClass.lpszClassName = TEXT("WS_RAYCASTING");
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hInstance = hInst;
    wndClass.style = CS_VREDRAW | CS_HREDRAW;
    wndClass.lpfnWndProc = WndProc;

    RegisterClass(&wndClass);

    AllocConsole();

    HWND window_handle = CreateWindow(wndClass.lpszClassName, TEXT("Raycasting"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, hInst, NULL);
    if (window_handle == NULL)
        return EXIT_FAILURE;

    UpdateWindow(window_handle);
    ShowWindow(window_handle, nCmdShow);

    Trace("1. Hello!");
    Trace("2. Hello!");

    MSG msg = { 0 };

    while (!global_exit)
    {
        Sleep(1);

        while (PeekMessage(&msg, window_handle, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }


    FreeConsole();

    DestroyWindow(window_handle);
    UnregisterClass(wndClass.lpszClassName, hInst);

    return EXIT_SUCCESS;
}