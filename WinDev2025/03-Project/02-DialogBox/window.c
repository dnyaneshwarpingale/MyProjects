#define UNICODE
// Win32 headers
#include <windows.h>

#include "Window.h"
    

#define Height 800
#define Width 600
// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK MyDlgProc(HWND, UINT, WPARAM, LPARAM);
 
//Globally declared structure
struct INPUT
{
    WCHAR name[50], address[50];  
    int age, mstatus;
    float sal;
};

int r = 255;
int g = 255; 
int b = 255;

BOOL flag = FALSE;

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
                        Width, // width
                        Height, // height
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
    
    unsigned int x = 8;
    unsigned int y = 16;
    static HINSTANCE hInst;
    static RECT rect; //it is an struct
    HDC hdc = NULL; //handle to device context
    PAINTSTRUCT ps;
    TCHAR str[] = TEXT("Hello World WinDev-2025");//Unicode string
   

    switch (iMsg)
    {
    case WM_CREATE:
        hInst = ((LPCREATESTRUCT)lParam)->hInstance;
        
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

        SetBkColor(hdc, RGB(0, 0, 0)); //color=8bit set text background to black color
        SetTextColor(hdc, RGB(r, g, b)); //set textcolor to green

        //Draw the text int Window's client area

        DrawText(hdc, str, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        if (hdc) {
            //release the painter
            EndPaint(hwnd, &ps);
            hdc = NULL;
        }

        break;

    case WM_KEYDOWN:
        switch (wParam) {
        case  VK_SPACE:
            DialogBox(hInst, MAKEINTRESOURCE(DATAENTRY), hwnd, MyDlgProc);
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

//Dialog Box Procedure

INT_PTR CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    char salrs[60], salps[3];
    struct INPUT in;
    switch (iMsg)
    {
    case WM_INITDIALOG:
        //set focus in name Edit Box
        SetFocus(GetDlgItem(hDlg, ID_ETNAME));

        //keep married Radio Button checked
        SendDlgItemMessage(hDlg, ID_RBMARRIED, BM_SETCHECK, 1, 0);
        return (TRUE);

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        //case ID_PBCONTINUE:
            //whatever task you want.......
        
            //EndDialog(hDlg, 0);
            //break;

        case IDOK:
            r = 0;
            g = 255;
            b = 0;

            InvalidateRect(hDlg, NULL, TRUE); 
            //Get the user-entered name
           // GetDlgItemText(hDlg, ID_ETNAME, in.name, 50);

            //Get the user-enterd address
           // GetDlgItemText(hDlg, ID_ETADDRESS, in.address, 50);

            //Get user-enterd age
            //GetDlgItemText(hDlg, ID_ETAGE, in.age, NULL, TRUE);

            //GetDlgItemText(hDlg, ID_ETSALRS, salrs, 6);
            //GetDlgItemText(hDlg, ID_ETSALPS, salps, 3);

            //in.sal = atoi(salrs) + (float)atoi(salps / 100);

            //Get user-entered marital status
            //in.mstatus = SendDlgItemMessage(hDlg, ID_RBMARRIED, BM_GETCHECK, 0, 0);

            //EndDialog(hDlg, 0);
            break;
            
        case IDCANCEL:
            EndDialog(hDlg, 0);
            break;
        }
        return(TRUE);
    }
    return (FALSE);
}//End of Dialog Procedure  


