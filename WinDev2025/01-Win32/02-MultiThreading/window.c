// Win32 headers
#include <windows.h>

#include "Window.h"

// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//globa declaration of of thread function
DWORD WINAPI ThreadProc1(LPVOID);
DWORD WINAPI ThreadProc2(LPVOID);

// Entry-point function
// first thread.winmain is the first thread and primary thread of our program.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)// process chya ayshyachi survat 
{
    // Variable declarations
    WNDCLASSEX wndClass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("DHP_Window");

    // Code
    memset((void *)&wndClass, 0, sizeof(WNDCLASSEX));
    // Window class initialization
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.lpfnWndProc = WndProc;
    wndClass.hInstance = hInstance;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(DHP_ICON));
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpszClassName = szAppName;
    wndClass.lpszMenuName = NULL;
    wndClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(DHP_ICON));

    // Registration of window class
    RegisterClassEx(&wndClass);
    // Create window
    hwnd = CreateWindow(szAppName,                   // name of your window class
                        TEXT("DHP:My First Window"), // window caption bar text
                        WS_OVERLAPPEDWINDOW,         // window style overlappedwindow
                                             //  it is combination of 6 window styles ws_overlapped | ws_caption |
                        //  ws_thickframe | ws_sysmenu | ws_minimizebox | ws_maximizebox
                        CW_USEDEFAULT, // x from desktop origin
                        CW_USEDEFAULT, // create window y from desktop origin
                        CW_USEDEFAULT, // width
                        CW_USEDEFAULT, // height
                        NULL,          // parent window here is desktop window is parent or HWND_DESKTOP
                        NULL,          //  HMENU HANDLE OF MENU
                        hInstance,     // handle to instance
                        NULL);         //
                                       // create window creates the window only in only in memory
    // Show window
    ShowWindow(hwnd, iCmdShow);

    // Paint background of window
    UpdateWindow(hwnd);

    // Message loop
    while (GetMessage(&msg, NULL, 0, 0)) // second parameter -> handle to the window ... null--> because default msges and child window msges
    {                                    // parameter 3 and 4--> min and max limit of msges
        TranslateMessage(&msg);          // simplify the msg
        DispatchMessage(&msg);
    }

    return ((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Code
    //varible declaration
    TCHAR str[255];
    unsigned int x = 0;
    unsigned int y = 0;
    static HANDLE hThread1 = NULL;
    static HANDLE hThread2 = NULL;

    

    switch (iMsg)
    {
    case WM_CREATE:
        hThread1 = CreateThread(
            NULL, //security descriptor ya thread cha handle inheritance //LPSECURITY_ATTRIBUTES null-->OS TU DEFAULT SECURITY DE
            0,        // STACK SIZE //0==DEFAULT STACK SIZE IN BYTES
            (LPTHREAD_START_ROUTINE)ThreadProc1,    //JYA FN CHI THREAD BANVAYCHI TYA FN CH NAV DYA 
            (LPVOID)hwnd,  //YOU WANT SEND PARAMETER ACTULLY PARAMETER THREAD FN
            0,        // thread creation flag // create zalya zalya run karayla survat kr
            NULL);//it gives thread id //pointer to thread id

        hThread2 = CreateThread(
            NULL, 
            0,
            (LPTHREAD_START_ROUTINE)ThreadProc2,
            (LPVOID)hwnd, 
            0,
            NULL); 
        break;

    case WM_KEYDOWN:
        switch (wParam) {
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;
        }

        break;

    case WM_LBUTTONDOWN:
        MessageBox(NULL, TEXT("This is Message Box Thread"), TEXT("Thread 4"), MB_OK);//these is our 4th thread
        break;

    case WM_DESTROY:
       // MessageBox(NULL, TEXT("WM_DESTROY arrived"), TEXT("Message"), MB_OK);

        //uninitialization thread
        if (hThread2) 
        {
            CloseHandle(hThread2); 
            hThread2 = NULL;

        }

        if (hThread1)
        {
            CloseHandle(hThread1);
            hThread1 = NULL;

        }

        PostQuitMessage(0); // parameter of postquitmsg 0 is wparam of wm_quit
        break;              // from this above 3line are  the message handler of wm_destroy

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam)); // default window procedure .. operating system window procedure
} // it send all handled and unhandled messages to os

//Defining thredProc1() ==(this is the second thread of our program)
DWORD WINAPI ThreadProc1(LPVOID param)
{
    //variable declarations
    HDC hdc = NULL;
    UINT i = 0;
    TCHAR str[255];

    //code
    hdc = GetDC((HWND)param);

    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(0, 255, 0));

    for (i = 0; i < UINT_MAX; i++)
    {
        wsprintf(str, TEXT("Incrementing : %u"), i);
        TextOut(hdc, 5, 10, str, wcslen(str));
    }

    if (hdc)
    {
        ReleaseDC((HWND)param, hdc);
        hdc = NULL;

    }

    return 0;
}


//Defining thredProc2() ==(this is the third thread of our program)
DWORD WINAPI ThreadProc2(LPVOID param)
{
    //variable declarations
    HDC hdc = NULL;
    UINT i = 0;
    TCHAR str[255];

    //code
    hdc = GetDC((HWND)param);

    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(255, 0, 0));

    for (i = UINT_MAX; i >= 0; i--)
    {
        wsprintf(str, TEXT("Decrementing : %u"), i);
        TextOut(hdc, 10, 30, str, wcslen(str));
    }

    if (hdc)
    {
        ReleaseDC((HWND)param, hdc);
        hdc = NULL;

    }

    return 0;
}