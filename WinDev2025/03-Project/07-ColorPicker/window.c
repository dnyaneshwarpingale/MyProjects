// Win32 headers
#include <windows.h>

#include <windowsx.h> // Get_x_lparam and y_param

#include "Window.h"
#include <stdio.h>  //for file io




// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// step-2 Declaring global file pointer.
FILE* gpFile_userLog = NULL;
FILE* gpFile_ColorPicker = NULL;
FILE* gpFile_ForRTR = NULL;
 
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
    // function declaration
    BOOL CreateAndOpenAllLogFile(void);
    void    CloseAllLogFile(void);

    //varible declaration
    TCHAR str[255];
    PAINTSTRUCT ps;
    HDC hdc, hMemdc;
    static HBITMAP hBitmapRec;
    static unsigned int resizedWindowWidth = 0;
    static unsigned int resizedWindowHeight = 0;

  // color picking related variables
    static unsigned int pickedPixelXCoord = 0;
    static unsigned int pickedPixelYCoord = 0;

    static BOOL bleftClickForColorPicking = FALSE;



    switch (iMsg)
    {
    case WM_CREATE:
        if (CreateAndOpenAllLogFile() == FALSE)
        {
            DestroyWindow(hwnd);
        }
        hBitmapRec = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,MAKEINTRESOURCE(DHP_BITMAP));

        //step-3 creating and opening user log file
        CreateAndOpenAllLogFile();
       
        if (hBitmapRec)
        {

        }


        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps); 
        hMemdc = CreateCompatibleDC(hdc); 

        SelectObject(hMemdc, hBitmapRec); 

        SetStretchBltMode(hdc, COLORONCOLOR);
        StretchBlt(hdc, 0, 0, resizedWindowWidth, resizedWindowHeight, hMemdc, 0, 0,800, 600, SRCCOPY); 
        
        if (bleftClickForColorPicking == TRUE) // Do color picking and log entry only when leftmouse button click.
        {
            // get Pixel color at( pickedPixelXcoord,pickedPixelYcoord)
            COLORREF pickedPixelColorRGB = GetPixel(hdc, pickedPixelXCoord, pickedPixelYCoord);
            unsigned int pickedPixelColorR = GetRValue(pickedPixelColorRGB);
            unsigned int pickedPixelColorG = GetGValue(pickedPixelColorRGB);
            unsigned int pickedPixelColorB = GetBValue(pickedPixelColorRGB);

            //Enter make entry of the picked color in RGB in the colorpicker log file.
            fprintf(gpFile_userLog, "User picked a color.\n");

            fprintf(gpFile_ColorPicker, "User picked color RGB = (%u,%u,%u)\n", pickedPixelColorR, pickedPixelColorG, pickedPixelColorB);

           
            float normalizedRed = (float)pickedPixelColorR / 255.0f;
            float normalizedGreen = (float)pickedPixelColorG / 255.0f;
            float normalizedBlue = (float)pickedPixelColorB / 255.0f;

            fprintf(gpFile_ForRTR, "User picked color RGB = (%f,%f,%f)\n", normalizedRed, normalizedGreen, normalizedBlue);

            bleftClickForColorPicking = FALSE;
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

    case WM_LBUTTONDOWN: //to pick the color
        bleftClickForColorPicking = TRUE; 

        pickedPixelXCoord = GET_X_LPARAM(LOWORD(lParam));
        pickedPixelYCoord = GET_Y_LPARAM(LOWORD(lParam));

        // Trigger WM_PAINT MESSAGE AGAIN TO REPAINT IMAGE AND GET PIXEL COLOR AT PICKEDpIXELXCOORD AND PICKEDPIXELYCOORD 
        InvalidateRect(hwnd, NULL, TRUE);

        break;


    case WM_SIZE:
        resizedWindowWidth = LOWORD(lParam);
        resizedWindowHeight = HIWORD(lParam);
        break;



    case WM_KEYDOWN:
        switch (wParam) 
        {
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;
        }

        break;

    case WM_DESTROY:
        CloseAllLogFile();
        MessageBox(NULL, TEXT("WM_DESTROY arrived"), TEXT("Message"), MB_OK);
        PostQuitMessage(0); // parameter of postquitmsg 0 is wparam of wm_quit
        break;              // from this above 3line are  the message handler of wm_destroy

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam)); // default window procedure .. operating system window procedure
} // it send all handled and unhandled messages to os

BOOL    CreateAndOpenAllLogFile(void)
{
    //code
    gpFile_userLog = fopen(TEXT("DHP_TESTUSERLOG.txt"), "w");//w open the log file for writing purpose.
    if (gpFile_userLog == NULL)
    {
        MessageBox(NULL, TEXT("Log file could not be created"), TEXT("LogFile_Error"), MB_OK | MB_ICONERROR);
       
    }
    // step -4 making first user log file entry
    fprintf(gpFile_userLog, "Program started successsfully.\n");
    fprintf(gpFile_userLog, "User log file created and opened successfully.\n"); 

    gpFile_ColorPicker = fopen(TEXT("DHP_TestColorPickerLog.txt"), "w");

    if (gpFile_ColorPicker == NULL)
    {
        MessageBox(NULL, TEXT("ColorPicker Log file could not be created"), TEXT("LogFile_Error"), MB_OK | MB_ICONERROR);
       
    }

 
    gpFile_ForRTR = fopen(TEXT("DHP_TestColorForRTRLog.txt"), "w");
    if (gpFile_ForRTR == NULL)
    {
        MessageBox(NULL, TEXT("ColorLog_rtr Log file could not be created"), TEXT("LogFile_Error"), MB_OK | MB_ICONERROR);
        
    }
    fprintf(gpFile_ForRTR, "Normalized Colors between 0 and 1.\n");

    return TRUE;
}

void    CloseAllLogFile(void)
{
    //code
    if (gpFile_ForRTR)
    {
        fclose(gpFile_ForRTR);
        gpFile_ForRTR = NULL;
    }
    if (gpFile_ColorPicker)
    {
        fclose(gpFile_ColorPicker);
        gpFile_ColorPicker = NULL;
    }

    if (gpFile_userLog)  // if file the whos pointer gpFile_userlog is exist
    {
        fprintf(gpFile_userLog, "User log file terminated  successfully.\n");
        fclose(gpFile_userLog);
        gpFile_userLog = NULL;
    }
}



