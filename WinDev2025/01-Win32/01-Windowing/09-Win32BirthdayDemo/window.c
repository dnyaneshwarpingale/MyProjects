// Win32 headers
#include <windows.h>

#include "Window.h"

//Link with library for playsound()
#pragma comment(lib, "winmm.lib")  //windows multimedia


// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

 
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
                         250, // x from desktop origin
                         110, // create window y from desktop origin
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
    static int r = 255 ;
    static int g =0 ;
    static int b =0;
    static BOOL bGofromleftToRight = TRUE; 

    static BOOL bReset = TRUE;

    TCHAR str[] = TEXT("HAPPY BIRTHDAY WIN32"); 
    static HANDLE hThread1 = NULL; 

    static int y1 = -CIRCLE_DIAMETER * 0; 
    static int y2 = -CIRCLE_DIAMETER * 1;
    static int y3 = -CIRCLE_DIAMETER * 2;
    static int y4 = -CIRCLE_DIAMETER * 3;
    static int y5 = -CIRCLE_DIAMETER * 4;
    static  int x = 0;

    static int y6 = -CIRCLE_DIAMETER * 0;
    static int y7 = -CIRCLE_DIAMETER * 1;
    static int y8 = -CIRCLE_DIAMETER * 2;
    static int y9 = -CIRCLE_DIAMETER * 3;
    static int y10 = -CIRCLE_DIAMETER * 4;
    static int y11 = -CIRCLE_DIAMETER * 5;
    static int y12 = -CIRCLE_DIAMETER * 6;
    static int y13 = -CIRCLE_DIAMETER * 7;

    static  int z;

    static int  cxClient, cyClient; 
  
//code

    switch (iMsg)
    {
    case WM_CREATE:

        //START playing the music
        PlaySound(MAKEINTRESOURCE(DHP_WAVE), GetModuleHandle(NULL), SND_LOOP | SND_RESOURCE | SND_ASYNC); 
        SetTimer(hwnd, DHP_TIMER, 50, NULL);//3s=3000ms
        break;

    case WM_SIZE: 
        cxClient = LOWORD(lParam); 
        cyClient = HIWORD(lParam); 
        return 0;
    
    case WM_PAINT:
        //0 out the memory of rect struct varible
        memset((void*)&rect, 0, sizeof(RECT));

        //get the wnd client area rectangle

        GetClientRect(hwnd, &rect);

        if (bReset) {
            y = rect.bottom - CIRCLE_DIAMETER ;

        }
       

        //0 out the memory of ps struct varible
        memset((void*)&ps, 0, sizeof(PAINTSTRUCT));

        //obtain hdc painter

        hdc = BeginPaint(hwnd, &ps);

        hBrush = CreateSolidBrush(RGB(0, 255, 0));

        //give the selected to the painter
        SelectObject(hdc, hBrush);

        Rectangle(hdc, cxClient / 8, cyClient / 8,7 * cxClient / 8, 7 * cyClient / 8);

        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }
        MoveToEx(hdc, 0, 0, NULL);

        LineTo(hdc, cxClient, cyClient);

        MoveToEx(hdc, 0, cyClient, NULL);

        LineTo(hdc, cxClient, 0);

       // Ellipse(hdc, cxClient / 8, cyClient / 8, 7 * cxClient / 8, 7 * cyClient / 8);
        hBrush = CreateSolidBrush(RGB(r, g, b)); 

        //give the selected to the painter
        SelectObject(hdc, hBrush); 

        RoundRect(hdc, cxClient / 4, cyClient / 4, 3 * cxClient / 4, 3 * cyClient / 4, cxClient / 4, cyClient / 4);

        if (hBrush)
        {
            DeleteObject(hBrush); 
            hBrush = NULL;

        }

        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color 
        SetTextColor(hdc, RGB(r, g, b)); //set textcolor to green 


        DrawText(hdc, str, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_WORDBREAK);   

        //create brush of desire color
        hBrush = CreateSolidBrush(RGB(r, g, b));
     
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

        hBrush = CreateSolidBrush(RGB(r, g, b));

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

        hBrush = CreateSolidBrush(RGB(255, 255, 255));

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

        hBrush = CreateSolidBrush(RGB(r, g, b));

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

        hBrush = CreateSolidBrush(RGB(255, 255, 255));

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

        hBrush = CreateSolidBrush(RGB(r, g, b)); //yellow

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

        hBrush = CreateSolidBrush(RGB(r, g, b));

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

        hBrush = CreateSolidBrush(RGB(255, 255, 255));

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

        hBrush = CreateSolidBrush(RGB(r, g, b));

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

        hBrush = CreateSolidBrush(RGB(255, 255, 255));

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

        hBrush = CreateSolidBrush(RGB(255, 0, 0));


        //give the selected to the painter
        SelectObject(hdc, hBrush); 


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, x, y1, x + CIRCLE_DIAMETER, y1 + CIRCLE_DIAMETER);

        SetBkMode(hdc, TRANSPARENT); 

       
       HRGN hRgn = CreateEllipticRgn(x, y1, x + CIRCLE_DIAMETER, y1 + CIRCLE_DIAMETER); 
       

        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(255, 255, 255)); //set textcolor    
        

        RECT textRect = { x, y1, x + CIRCLE_DIAMETER, y1 + CIRCLE_DIAMETER }; 

        DrawText(hdc, "H", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
        Ellipse(hdc, x, y2, x + CIRCLE_DIAMETER, y2 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(x, y2, x + CIRCLE_DIAMETER, y2 + CIRCLE_DIAMETER);
       

        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(255, 255, 255)); //set textcolor   
        

        textRect.left = x;
        textRect.top = y2;
        textRect.right = x + CIRCLE_DIAMETER;
        textRect.bottom = y2 + CIRCLE_DIAMETER;

        DrawText(hdc, "A", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



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
        Ellipse(hdc, x, y3, x + CIRCLE_DIAMETER, y3 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(x, y3, x + CIRCLE_DIAMETER, y3 + CIRCLE_DIAMETER);
       

        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(255, 255, 255)); //set textcolor    
        

        textRect.left = x;
        textRect.top = y3;
        textRect.right = x + CIRCLE_DIAMETER;
        textRect.bottom = y3 + CIRCLE_DIAMETER;

        DrawText(hdc, "P", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
        Ellipse(hdc, x, y4, x + CIRCLE_DIAMETER, y4 + CIRCLE_DIAMETER);


        hRgn = CreateEllipticRgn(x, y4, x + CIRCLE_DIAMETER, y4 + CIRCLE_DIAMETER);
        

        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(255, 255, 255)); //set textcolor    
        // Set text alignment (centered)

        textRect.left = x;
        textRect.top = y4;
        textRect.right = x + CIRCLE_DIAMETER;
        textRect.bottom = y4 + CIRCLE_DIAMETER;

        DrawText(hdc, "P", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
        Ellipse(hdc, x, y5, x + CIRCLE_DIAMETER, y5 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(x, y5, x + CIRCLE_DIAMETER, y5 + CIRCLE_DIAMETER);


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(255, 255, 255)); //set textcolor  
        // Set text alignment (centered)

        textRect.left = x;
        textRect.top = y5;
        textRect.right = x + CIRCLE_DIAMETER; 
        textRect.bottom = y5 + CIRCLE_DIAMETER; 

        DrawText(hdc, "Y", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(255, 255, 0)); //yellow

        //give the selected to the painter
        SelectObject(hdc, hBrush);

       z = (rect.right - rect.left) - CIRCLE_DIAMETER;

        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, z, y6, z + CIRCLE_DIAMETER, y6 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(z, y6, z + CIRCLE_DIAMETER, y6 + CIRCLE_DIAMETER); 


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(0, 0, 0)); //set textcolor   
       

        textRect.left = z; 
        textRect.top = y6; 
        textRect.right = z + CIRCLE_DIAMETER; 
        textRect.bottom = y6 + CIRCLE_DIAMETER;

        DrawText(hdc, "B", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
        Ellipse(hdc, z, y7, z + CIRCLE_DIAMETER, y7 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(z, y7, z + CIRCLE_DIAMETER, y7 + CIRCLE_DIAMETER);


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(0, 0, 0)); //set textcolor to 
        

        textRect.left = z;
        textRect.top = y7;
        textRect.right = z + CIRCLE_DIAMETER;
        textRect.bottom = y7 + CIRCLE_DIAMETER;

        DrawText(hdc, "I", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        
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
        Ellipse(hdc, z, y8, z + CIRCLE_DIAMETER, y8 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(z, y8, z + CIRCLE_DIAMETER, y8 + CIRCLE_DIAMETER);


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(0, 0, 0)); //set textcolor to green   
        // Set text alignment (centered)

        textRect.left = z;
        textRect.top = y8;
        textRect.right = z + CIRCLE_DIAMETER;
        textRect.bottom = y8 + CIRCLE_DIAMETER;

        DrawText(hdc, "R", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
        Ellipse(hdc, z, y9, z + CIRCLE_DIAMETER, y9 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(z, y9, z + CIRCLE_DIAMETER, y9 + CIRCLE_DIAMETER);


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(0, 0, 0)); //set textcolor    
      

        textRect.left = z;
        textRect.top = y9;
        textRect.right = z + CIRCLE_DIAMETER;
        textRect.bottom = y9 + CIRCLE_DIAMETER;

        DrawText(hdc, "T", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
        Ellipse(hdc,z, y10, z + CIRCLE_DIAMETER, y10 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(z, y10, z + CIRCLE_DIAMETER, y10 + CIRCLE_DIAMETER);


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(0, 0, 0)); //set textcolor    
       

        textRect.left = z;
        textRect.top = y10;
        textRect.right = z + CIRCLE_DIAMETER;
        textRect.bottom = y10 + CIRCLE_DIAMETER;

        DrawText(hdc, "H", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        //delet the brush
        if (hBrush)
        {
            DeleteObject(hBrush);
            hBrush = NULL;

        }

        hBrush = CreateSolidBrush(RGB(255, 0, 0));

        //give the selected to the painter 
        SelectObject(hdc, hBrush);


        //make the painter color the client area rectangle with selected brush
        Ellipse(hdc, z, y11, z + CIRCLE_DIAMETER, y11 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(z, y11, z + CIRCLE_DIAMETER, y11 + CIRCLE_DIAMETER);


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(0, 0, 0)); //set textcolor    


        textRect.left = z;
        textRect.top = y11;
        textRect.right = z + CIRCLE_DIAMETER;
        textRect.bottom = y11 + CIRCLE_DIAMETER;

        DrawText(hdc, "D", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
        Ellipse(hdc, z, y12, z + CIRCLE_DIAMETER, y12 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(z, y12, z + CIRCLE_DIAMETER, y12 + CIRCLE_DIAMETER);


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(0, 0, 0)); //set textcolor    


        textRect.left = z;
        textRect.top = y12;
        textRect.right = z + CIRCLE_DIAMETER;
        textRect.bottom = y12 + CIRCLE_DIAMETER;

        DrawText(hdc, "A", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
        Ellipse(hdc, z, y13, z + CIRCLE_DIAMETER, y13 + CIRCLE_DIAMETER);

        hRgn = CreateEllipticRgn(z, y13, z + CIRCLE_DIAMETER, y13 + CIRCLE_DIAMETER);


        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color  
        SetTextColor(hdc, RGB(0, 0, 0)); //set textcolor    


        textRect.left = z;
        textRect.top = y13;
        textRect.right = z + CIRCLE_DIAMETER;
        textRect.bottom = y13 + CIRCLE_DIAMETER;

        DrawText(hdc, "Y", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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

        y1 = y1 + 1;
        y2++;
        y3++; 
        y4++;
        y5++;
        y6++;
        y7++;
        y8++;
        y9++;
        y10++;
        y11++;
        y12++;
        y13++;

        //reseting the value of coordinats
        if (y13 > rect.bottom) 
        {
            y1 = -CIRCLE_DIAMETER * 0;
            y2 = -CIRCLE_DIAMETER * 1;
            y3 = -CIRCLE_DIAMETER * 2;
            y4 = -CIRCLE_DIAMETER * 3;
            y5 = -CIRCLE_DIAMETER * 4;
            y6 = -CIRCLE_DIAMETER * 1;
            y7 = -CIRCLE_DIAMETER * 2;
            y8 = -CIRCLE_DIAMETER * 3;
            y9 = -CIRCLE_DIAMETER * 4;
            y10 = -CIRCLE_DIAMETER * 5;
            y11 = -CIRCLE_DIAMETER * 6;
            y12 = -CIRCLE_DIAMETER * 7;
            y13 = -CIRCLE_DIAMETER * 8;

        }

        if (bGofromleftToRight) {
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
            if (x1 == rect.right - CIRCLE_DIAMETER)
            {
               
                    bGofromleftToRight = FALSE; 
            }
        }
        else {
            x1--;
            x2--;
            x3--;
            x4--;
            x5--;
            x6--;
            x7--;

            x8--;
            x9--;
            x10--; 
            if ( x10 ==rect.left)  
            {
                bGofromleftToRight = TRUE; 
            }
        }
      

        
        
        if (r == 255 && g == 0 && b == 0)
        {
            r = 0;
            g = 255;
            b = 0;

        }
        else if (r == 0 && g == 255 && b == 0)
        {
            r = 0;
            g = 0;
            b = 255;
            
        }
        else if (r == 0 && g == 0 && b == 255) {
            r = 0;
            b = 255;
            g = 255;
        }
        else if (r == 0 && g == 255 && b == 255) {
            r = 255;
            b = 0;
            g = 255;
        }
        else if (r == 255 && g == 0 && b == 255) {
            r = 255;
            b = 255;
            g = 0;
        }
        else if (r == 255 && g == 255 && b == 0) {
            r = 255;
            b = 128;
            g = 0;
        }
        else if (r == 255 && g == 128 && b == 0) {
            r = 128;
            b = 128;
            g = 255;
        }
        else
        {
            r = 255;
            g = 0;
            b = 0;
        }
      
        
        
        //reseting the value of coordinats
       /* if (x10 > rect.right)
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
        }*/
       

        InvalidateRect(hwnd, NULL, TRUE); 
        SetTimer(hwnd, DHP_TIMER, 50, NULL);//3s=3000ms
        break;
    
    case WM_LBUTTONDOWN:
     /*   x1 = LOWORD(lParam);
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
        y=HIWORD(lParam);*/

        y1 = HIWORD(lParam); 
        y2 = y1 - CIRCLE_DIAMETER * 1;
        y3 = y1 - CIRCLE_DIAMETER * 2;
        y4 = y1 - CIRCLE_DIAMETER * 3;
        y5 = y1 - CIRCLE_DIAMETER * 4;
        y6 = y1 - CIRCLE_DIAMETER * 5;
        y7 = y1 - CIRCLE_DIAMETER * 6;
        y8 = y1 - CIRCLE_DIAMETER * 7;
        y9 = y1 - CIRCLE_DIAMETER * 8;
        y10 = y1 - CIRCLE_DIAMETER * 9;

        bReset = FALSE; 
        x = LOWORD(lParam);
     
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
