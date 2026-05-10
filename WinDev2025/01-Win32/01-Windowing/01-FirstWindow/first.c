// Win32 headers
#include <windows.h>

// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entry-point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // Variable declarations
    WNDCLASSEX wndClass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("DHP_Window");

    // Code
    memset((void*)&wndClass, 0, sizeof(WNDCLASSEX));
    // Window class initialization
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.lpfnWndProc = WndProc;
    wndClass.hInstance = hInstance; 
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpszClassName = szAppName;
    wndClass.lpszMenuName = NULL;
    wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // Registration of window class
    RegisterClassEx(&wndClass);
    // Create window
    hwnd = CreateWindow(szAppName,//name of your window class 
                        TEXT("DHP:My First Window"), //window caption bar text
                        WS_OVERLAPPEDWINDOW,  //window style overlappedwindow 
                             // it is combination of 6 window styles ws_overlapped | ws_caption | 
                            //  ws_thickframe | ws_sysmenu | ws_minimizebox | ws_maximizebox
                        CW_USEDEFAULT, // x from desktop origin 
                        CW_USEDEFAULT,  // create window y from desktop origin
                        CW_USEDEFAULT, //width
                        CW_USEDEFAULT, // height
                        NULL, // parent window here is desktop window is parent or HWND_DESKTOP
                        NULL, //  HMENU HANDLE OF MENU
                        hInstance, // handle to instance 
                        NULL);  //
// create window creates the window only in only in memory
    // Show window
    ShowWindow(hwnd, iCmdShow);

    // Paint background of window
    UpdateWindow(hwnd);

    // Message loop
    while (GetMessage(&msg, NULL, 0, 0))  //second parameter -> handle to the window ... null--> because default msges and child window msges
    {                                    // parameter 3 and 4--> min and max limit of msges
        TranslateMessage(&msg);// simplify the msg
        DispatchMessage(&msg);
    }

    return ((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Code

    switch (iMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0); // parameter of postquitmsg 0 is wparam of wm_quit
        break;            // from this above 3line are  the message handler of wm_destroy

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam));  // default window procedure .. operating system window procedure
}    // it send all handled and unhandled messages to os 
