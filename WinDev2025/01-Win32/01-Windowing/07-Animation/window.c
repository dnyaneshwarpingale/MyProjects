// Win32 headers
#include <windows.h>

#include "Window.h"


// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define ELLIPSE_SIZE_X 100
#define ELLIPSE_SIZE_Y 100
 
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
                       0, // x from desktop origin
                       0, // create window y from desktop origin
                       WINDOW_WIDTH, // width
                       WINDOW_HEIGHT, // height
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
    static int leftTopx ;
    static int leftTopy ;
    static int rightbottemx ;
    static int rightbottemy;
    static int xAnimate = 0;
    static BOOL bGofromTopToBottom = TRUE; 
    static int leftTopxr; 
    static int leftTopyr; 
    static int rightbottemxr; 
    static int rightbottemyr;
    static int yAnimate = 0; 
    static BOOL bGofromleftToRight = TRUE;

    static int leftTopxa;
    static int leftTopyb;
    static int rightbottemxa;
    static int rightbottemyb; 

 

  
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

        //0 out the memory of ps struct varible
        memset((void*)&ps, 0, sizeof(PAINTSTRUCT));

        //obtain hdc painter

        hdc = BeginPaint(hwnd, &ps);

        //create brush of desire color
        hBrush = CreateSolidBrush(RGB(255, 0, 0));
        
          //give the selected brush to the painter
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
       // FillRect(hdc, &rect, hBrush);
        leftTopx = (WINDOW_WIDTH / 2) - (ELLIPSE_SIZE_X / 2); 
        leftTopy = 0 + xAnimate;
        rightbottemx = (WINDOW_WIDTH / 2) + (ELLIPSE_SIZE_X / 2);
        rightbottemy = ELLIPSE_SIZE_X + xAnimate;
        Ellipse(hdc, leftTopx, leftTopy, rightbottemx, rightbottemy); //invisible choukonamadhe(rectangle) circle 

        // Set transparent background mode
        SetBkMode(hdc, TRANSPARENT);

        HRGN hrgn = CreateEllipticRgn(leftTopx, leftTopy, rightbottemx, rightbottemy); 
        SelectClipRgn(hdc, hrgn);

        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color 
        SetTextColor(hdc, RGB(0, 255, 0)); //set textcolor to green  
        // Set text alignment (centered)

        RECT textRect = { leftTopx, leftTopy, rightbottemx, rightbottemy }; 

        DrawText(hdc, "Hello from Win32 Ellipse!", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


        //delet the brush
        if (hBrush)
        {
            DeleteObject(hrgn);
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
        }

        break;

    case WM_TIMER:
        KillTimer(hwnd, DHP_TIMER);
        if (bGofromTopToBottom)
        {
            xAnimate = xAnimate + 1;  
            if (rightbottemy == WINDOW_HEIGHT)  
            {
                bGofromTopToBottom = FALSE; 
            }
        }
        else
        {
            xAnimate = xAnimate - 1;
            if (leftTopy == 0)   
            {
                bGofromTopToBottom = TRUE; 
            }

        }

       
  

        if (bGofromleftToRight)
        {
            yAnimate = yAnimate + 1;
            
            if (rightbottemxr == WINDOW_HEIGHT/2)
            {
                
                bGofromleftToRight = FALSE; 
            }
        }
        else
        {
            yAnimate = yAnimate - 1; 
            if (leftTopxr == 0) 
            {
                bGofromleftToRight = TRUE; 
            }

        } 

        InvalidateRect(hwnd, NULL, TRUE);  
        SetTimer(hwnd, DHP_TIMER, 5, NULL);//3s=3000ms
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
