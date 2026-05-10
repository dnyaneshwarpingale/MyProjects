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

    return ((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Code
    //varible declaration
    TCHAR str[255];
    PAINTSTRUCT ps;
    HDC hdc, hMemdc;
    static HBITMAP hBitmapRec;
    static unsigned int resizedWindowWidth = 0;
    static unsigned int resizedWindowHeight = 0;
  //iterating variable
    unsigned int xColumn = 0;
    unsigned int yRow = 0;
    static BOOL bSPaceBar = FALSE;


    switch (iMsg)
    {
    case WM_CREATE:
        hBitmapRec = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,MAKEINTRESOURCE(DHP_BITMAP)); 
        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps); 
        hMemdc = CreateCompatibleDC(hdc); 

        SelectObject(hMemdc, hBitmapRec); 

        SetStretchBltMode(hdc, COLORONCOLOR);
        StretchBlt(hdc, 0, 0, resizedWindowWidth, resizedWindowHeight, hMemdc, 0, 0,800, 600, SRCCOPY); 
        
        //pixel by pixel desaturation nested loop.
        //outer loop handles rows and inner loop handles columns and desaturate it.
        for (yRow = 0; yRow < resizedWindowHeight; yRow++)
        {  
            
            if (bSPaceBar == TRUE)
            {
                
                for (xColumn = 0; xColumn < resizedWindowWidth; xColumn++)
                {
                   

                    // Get color from the pixel at coordinate (xColumn, yRow)
                    COLORREF originalPixelColor = GetPixel(hdc, xColumn, yRow);

                    // from original pixel color obtained in above step seperate out the Red Green and Blue components 
                    // using them calculate Negative NR NG and NB

                    unsigned int originalR = GetRValue(originalPixelColor);
                    unsigned int originalG = GetGValue(originalPixelColor);
                    unsigned int originalB = GetBValue(originalPixelColor);

                    // calculating dsaturated value
                    unsigned int negativeR = 255 - originalR; 
                    if (negativeR < 0) 
                    {
                        negativeR = 0;// in openGL campling mhantat
                    }
                    unsigned int negativeG = 255 - originalG; 
                    if (negativeG < 0)
                    {
                        negativeG = 0;// in openGL campling mhantat
                    }
                    unsigned int negativeB = 255 - originalB; 
                    if (negativeB < 0)
                    {
                        negativeB = 0;// in openGL campling mhantat  
                    }

               
                     
                    // set final dsaturated color back to the same pixel or at coordinate xColumn, yRow
                    COLORREF negativePixelColor = RGB(negativeR, negativeG, negativeB);
                    SetPixel(hdc, xColumn, yRow, negativePixelColor); 



                }
            }
        }

        if (hMemdc) 
        {
            DeleteDC(hMemdc);  
        }
        
        if (hdc)
        {
            EndPaint(hwnd, &ps); 
        }
       
        break;

    case WM_SIZE:
        resizedWindowWidth = LOWORD(lParam);
        resizedWindowHeight = HIWORD(lParam);
        break;

    case WM_KEYDOWN:
        switch (wParam) 
        {
        case VK_SPACE:
            
            bSPaceBar = TRUE;
            InvalidateRect(hwnd,NULL,TRUE); 
            break;
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;
        }

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


