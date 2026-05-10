// Win32 headers
#include <windows.h>

#include "Window.h"

#include "ClassFactoryDllServerWithRegFile.h"

// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global declaration of interface pointers.
ISum* pISum = NULL;  

ISubtract* pISubtract = NULL;

// Entry-point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)// process chya ayushyachi survat
{
    // Variable declarations
    WNDCLASSEX wndClass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("DHP_Window");
    HRESULT hr = S_OK;

    // Code
    //initializing com engine.
    hr = CoInitialize(NULL);// it is from ole32.lib 

    if (FAILED(hr))
    {
        MessageBox(NULL, TEXT("co Initilized failed"), TEXT("COM ERROR"), MB_OK | MB_ICONERROR);
        exit(0);

    }

    memset((void*)&wndClass, 0, sizeof(WNDCLASSEX));
    // Window class initialization
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.lpfnWndProc = WndProc;
    wndClass.hInstance = hInstance;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
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

    //Uninitializing the COM engine.
    CoUninitialize();//=>COfreeunusedlibraries()=>lpfn2=>DllCanUnloadNow()=>CoFreeLibrary()=>Freelibrary().


    return ((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Code
    // Function prototype
    void SafeInterfaceRelease(void);

    //varible declaration
    TCHAR str[255];
    unsigned int x = 0;
    unsigned int y = 0;
    HRESULT hr = S_OK;
    int num1 = 23;
    int num2 = 30;

    int sum = 0;
    int sub = 0;

    switch (iMsg)
    {
    case WM_CREATE:
        hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void**)&pISum); //CLSCTX_INPROC_SERVER==which type of server

        if (FAILED(hr))
        {
            MessageBox(NULL, TEXT("cocreate instance failed to obtain ISum interface"), TEXT("COM ERROR"), MB_OK | MB_ICONERROR);
            DestroyWindow(hwnd);
        }

        pISum->SumOfTwoIntegers(num1, num2, &sum);
        wsprintf(str, TEXT("Sum of %d and %d : %d"),num1,num2, sum); 
        MessageBox(NULL, str, TEXT("Message"), MB_OK); 

       hr = pISum->QueryInterface(IID_ISubtract ,(void **) & pISubtract);
       if (FAILED(hr))
       {
           MessageBox(NULL, TEXT("cocreate instance failed to obtain ISubtract interface"), TEXT("COM ERROR"), MB_OK | MB_ICONERROR);
           DestroyWindow(hwnd); 
       }

       pISubtract->SubtractionOfTwoIntegers(num1, num2, &sub);
       wsprintf(str, TEXT("Subtraction of %d and %d : %d"), num1, num2, sub);
       MessageBox(NULL, str, TEXT("Message"), MB_OK); 


        DestroyWindow(hwnd); 
        break;

    case WM_KEYDOWN:
        switch (wParam) {
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;
        }

        break;

    case WM_DESTROY:
        MessageBox(NULL, TEXT("WM_DESTROY arrived"), TEXT("Message"), MB_OK);
        SafeInterfaceRelease();
        PostQuitMessage(0); // parameter of postquitmsg 0 is wparam of wm_quit
        break;              // from this above 3line are  the message handler of wm_destroy

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam)); // default window procedure .. operating system window procedure
} // it send all handled and unhandled messages to os

//Userdefined function for safely releasing the interface pointer.
void SafeInterfaceRelease(void)
{
    //code
    if (pISubtract)
    {
        pISubtract->Release();
        pISubtract = NULL;

    }

    if (pISum)
    {
        pISum->Release();
        pISum = NULL;

    }
}
