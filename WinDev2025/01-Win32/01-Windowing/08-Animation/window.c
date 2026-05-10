// Win32 headers
#include <windows.h>

#include "Window.h"


// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
 
// Entry-point function
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
    UpdateWindow(hwnd); //sends wm_paint message

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
   
    //varible declaration
    static RECT rect; //it is an struct
    HDC hdc = NULL; //handle to device context
    PAINTSTRUCT ps;
    HBRUSH hBrush = NULL;//handle to brush
    static int x1 = -CIRCLE_DIAMETER * 0; 
    static int x2 = -CIRCLE_DIAMETER * 1;
    static int x3 = -CIRCLE_DIAMETER * 2;
    static int x4 = -CIRCLE_DIAMETER * 3;
    static int x5 = -CIRCLE_DIAMETER * 4; 
    static int x6 = -CIRCLE_DIAMETER * 5;
    static int x7 = -CIRCLE_DIAMETER * 6; 
    static int x8 = -CIRCLE_DIAMETER * 7;
    static int x9 = -CIRCLE_DIAMETER  * 8;
    static int x10 = -CIRCLE_DIAMETER * 9;

    static  int y = 0;

    static BOOL bReset = TRUE;


  
//code

    switch (iMsg)
    {
    case WM_CREATE:
        SetTimer(hwnd, DHP_TIMER, 5, NULL);//3s=3000ms
        break;

    case WM_PAINT:
        //0 out the memory of rect struct varible
        memset((void*)&rect, 0, sizeof(RECT));

        //get the wnd client area rectangle

        GetClientRect(hwnd, &rect);

        if (bReset) {
            y = (rect.bottom - rect.top) / 2;

        }
       

        //0 out the memory of ps struct varible
        memset((void*)&ps, 0, sizeof(PAINTSTRUCT));

        //obtain hdc painter

        hdc = BeginPaint(hwnd, &ps);

        //create brush of desire color
        hBrush = CreateSolidBrush(RGB(255, 0, 0));
     
          //give the selected to the painter
        SelectObject(hdc, hBrush);

        
        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x1, y, x1+ CIRCLE_DIAMETER, y+ CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(0, 255, 0));

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x2, y, x2 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(0, 0, 255));

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x3, y, x3 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(0, 255, 255));

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x4, y, x4 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(255, 0, 255));

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x5, y, x5 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(255, 255, 0)); //yellow

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x6, y, x6 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(255, 255, 255));

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x7, y, x7 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(128, 128, 128));

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x8, y, x8 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(255, 128, 0));

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x9, y, x9 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(128, 128, 255));

        //give the selected to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x10, y, x10 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        

        if (hdc) {
            //release the painter
            EndPaint(hwnd, &ps);
            hdc = NULL;
        }

        break;

    case WM_KEYDOWN:
        switch (wParam) {
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;

        case VK_UP:
            bReset = FALSE;
            y = y - 5;
            if (y < rect.top)
            {
                y = rect.top;
            }
            break;

        case VK_DOWN:
            bReset = FALSE; 
            y = y + 5;
            if (y > rect.bottom-CIRCLE_DIAMETER)
            {
                y = rect.bottom-CIRCLE_DIAMETER;
            }
            break;
        }

        break;

    case WM_CHAR:
        switch (wParam)
        {
        case 'R':
        case 'r':
            bReset = TRUE;
            break;

        default:
            break;
        }
        break;

    case WM_TIMER:
        KillTimer(hwnd, DHP_TIMER);
        x1 = x1 + 1;
        x2++;
        x3++; 
        x4++; 
        x5++;
        x6++; 
        x7++;
        x8++;
        x9++;
        x10++;
        
        //reseting the value of coordinats
        if (x10 > rect.right)
        {
             x1 = -CIRCLE_DIAMETER * 0;
             x2 = -CIRCLE_DIAMETER * 1;
             x3 = -CIRCLE_DIAMETER * 2;
             x4 = -CIRCLE_DIAMETER * 3;
             x5 = -CIRCLE_DIAMETER * 4;
             x6 = -CIRCLE_DIAMETER * 5;
             x7 = -CIRCLE_DIAMETER * 6;
             x8 = -CIRCLE_DIAMETER * 7;
             x9 = -CIRCLE_DIAMETER * 8;
             x10 = -CIRCLE_DIAMETER * 9;
        }

        InvalidateRect(hwnd, NULL, TRUE);
        SetTimer(hwnd, DHP_TIMER, 5, NULL);//3s=3000ms
        break;
    
    case WM_LBUTTONDOWN:
        x1=LOWORD(lParam);
        x2 =x1-CIRCLE_DIAMETER*1;
        x3=x1-CIRCLE_DIAMETER * 2;
        x4=x1-CIRCLE_DIAMETER * 3;
        x5=x1-CIRCLE_DIAMETER * 4;
        x6=x1-CIRCLE_DIAMETER * 5;
        x7=x1-CIRCLE_DIAMETER * 6;
        x8=x1-CIRCLE_DIAMETER * 7;
        x9=x1-CIRCLE_DIAMETER * 8;
        x10=x1-CIRCLE_DIAMETER * 9;

        bReset=FALSE;
        y=HIWORD(lParam);
     
        break;


    case WM_DESTROY:
        MessageBox(NULL, TEXT("WM_DESTROY arrived"), TEXT("Message"), MB_OK);
        PostQuitMessage(0); // parameter of postquitmsg 0 is wparam of wm_quit
        break;              // from this above 3line are  the message handler of wm_destroy

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam)); // default window procedure .. operating system window procedure
} // it send all handled and unhandled messages to os
