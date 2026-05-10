// Win32 headers
//#define UNICODE
//#define _UNICODE 
#include <windows.h>
#include <commdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windowsx.h>
#include "Window.h"



// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK MyDlgProc(HWND, UINT, WPARAM, LPARAM); 
INT_PTR CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM); 
INT_PTR CALLBACK RegisterDlgProc(HWND, UINT, WPARAM, LPARAM);


BOOL userRegistered = FALSE;
BOOL imageEffectChecked = FALSE;
HWND hwndmodeless;
int printOk = 1;
HWND hNonModalDlg = NULL;
int imageEffect = 0;
HBRUSH hDlgBrush;
HMENU hMenu = NULL;

static unsigned int resizedWindowWidth = 0;
static unsigned int resizedWindowHeight = 0;
//iterating variable
unsigned int xColumn = 0;
unsigned int yRow = 0; 

//global file handle;
HANDLE hf = NULL;

//Global bitmap handle
HBITMAP hBitmap = NULL;

//Global variables
HINSTANCE hInst;
TCHAR szMessage[50];
COLORREF textColor;
TCHAR firstName[100], middleName[100], lastName[100];
unsigned int pickedPixelColorR;
unsigned int pickedPixelColorG;
unsigned int pickedPixelColorB;


//functions
BOOL isValidName(const TCHAR*);
void CreateColorPickerLogFile(const char*, const char*);
void CreateNormalizedColorPickerLogFile(const char*, const char*);
void CreateUserLogFile(const char*, const char*);
void CloseAllLogFiles();

// global file pointers
FILE* gpFile_UserLog = NULL;
FILE* gpFile_ColorPickerLog = NULL;
FILE* gpFile_ColorPickerNormalizedLog = NULL;

HRESULT hr;
HWND hwnd = NULL;

 //HBRUSH hBrushRed = CreateSolidBrush(RGB(255, 0, 0));//Red Brush for invalid text
 //HBRUSH hBrushBlack = CreateSolidBrush(RGB(0, 0, 0));//Red Brush for invalid text 





 
// Entry-point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpszCmdLine, int iCmdShow)// process chya ayshyachi survat 
{
    // Variable declarations
    WNDCLASSEX wndClass;
    MSG msg;
    TCHAR szAppName[] = TEXT("DHP_Window");
    int screenWidth = GetSystemMetrics(SM_CXSCREEN); 
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);  

    int winWidth = screenWidth / 2;   // half width   
    int winHeight = screenHeight / 2;  // half height  

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
    wndClass.lpszMenuName = szAppName;
    wndClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(DHP_ICON));

    // Registration of window class
    RegisterClassEx(&wndClass);

    // load menu
     hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(MYMENU));

    // Create window
    hwnd = CreateWindow(szAppName,                   // name of your window class
                        TEXT("DHP:My First Window"), // window caption bar text
                        WS_OVERLAPPEDWINDOW,         // window style overlappedwindow
                                             //  it is combination of 6 window styles ws_overlapped | ws_caption |
                        //  ws_thickframe | ws_sysmenu | ws_minimizebox | ws_maximizebox
                        0, // x from desktop origin
                        0, // create window y from desktop origin
                        winWidth, // width
                        winHeight, // height 
                        NULL,          // parent window here is desktop window is parent or HWND_DESKTOP
                        hMenu,          //  HMENU HANDLE OF MENU
                        hInstance,     // handle to instance
                        NULL);         //
                                       // create window creates the window only in only in memory
    // Show window
    ShowWindow(hwnd, iCmdShow);

    // Paint background of window
    UpdateWindow(hwnd);

    // Message loop
    while (GetMessage(&msg, NULL, 0, 0)) // second parameter -> handle to the window ... null--> because default msges and child window msges
    {    
        if (hwndmodeless == NULL || (IsDialogMessage(hwndmodeless, &msg)==0))
        {                            // parameter 3 and 4--> min and max limit of msges
            TranslateMessage(&msg);           // simplify the msg
            DispatchMessage(&msg);
        }
    }
    // Clean up Bitmap before exiting
    if (hBitmap)
    {
        DeleteObject(hBitmap);
    }

    return ((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Code
    //varible declaration
    TCHAR str[255]; 
    static HWND hwndStatic = NULL; 

    HDC hdc = NULL; 
    static PAINTSTRUCT ps;  
   static RECT rect; // static to use across cases
   TCHAR buffer[10]; // A buffer to store the RGB VALUES AS TEXT

   //original window size
   static int windowWidth = 0;
   static int windowHeight = 0;


   static COLORREF originalPixelColor = NULL; 

   //initialize file dialog structure

   OPENFILENAME ofn; // comon dialog box structure
   CHAR szFile[260]; // BUFFER FOR FILE NAME.

   // COLOR PICKING RELATED VARIABLES 
   static unsigned int pickedPixelXCoord = 0;
   static unsigned int pickedPixelYCoord = 0;

   // void SafeInterfaceRelease();

   ZeroMemory(&ofn, sizeof(ofn));
   ofn.lStructSize = sizeof(ofn);
   ofn.lpstrFile = szFile;
   ofn.lpstrFile[0] = '\0';
   ofn.nMaxFile = sizeof(szFile);
   ofn.lpstrFilter = "Image Files\0*.BMP;*.JPEG;*.PNG\0BitMap Files\0*.*\0";// Filter for image files (BMP,JPEG,PNG)
   ofn.nFilterIndex = 1;
   ofn.lpstrFileTitle = 0;
   ofn.nMaxFileTitle = 0;
   ofn.lpstrInitialDir = NULL;
   ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;    
    

    switch (iMsg)
    {
    case WM_CREATE:
        hInst = ((LPCREATESTRUCT)lParam)->hInstance; 

        ZeroMemory((void*)&rect, sizeof(RECT)); 
        ZeroMemory((void*)&ps, sizeof(PAINTSTRUCT));

        windowWidth = GetSystemMetrics(SM_CXSCREEN) / 2;
        windowHeight = GetSystemMetrics(SM_CYSCREEN) / 2;

        SetWindowPos(hwnd, NULL, 0, 0, windowWidth, windowHeight, SWP_NOMOVE | SWP_NOZORDER);
        hMenu = GetMenu(hwnd);
        EnableMenuItem(hMenu, IDM_OPEN, MF_BYCOMMAND | MF_GRAYED);

        //disable the ImageEditor group box initially
         EnableWindow(GetDlgItem(hwnd, IDG_COLOR_PICKER), FALSE);
        //disable the ImageEditor group box initially
        EnableWindow(GetDlgItem(hwnd, IDG_IMAGE_EDITOR), FALSE);
        

        break;

    case WM_PAINT:
        //Get the Painter hdc to do painting work for our window
        hdc = BeginPaint(hwnd, &ps);

        if (hBitmap) // if a bitmap is loaded
        {
            HDC hMemdc = CreateCompatibleDC(hdc);
            SelectObject(hMemdc, hBitmap);
            BITMAP bitmap;
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);

            //Get the Client area size of the window
            RECT clientRect;
            GetClientRect(hwnd, &clientRect);
            int clientWidth = clientRect.right - clientRect.left;
            int clientHeight = clientRect.bottom - clientRect.top;

            //Stretch the bitmap to fill the entir client area
            SetStretchBltMode(hdc, HALFTONE); // Use HALFTONE FOR BETTERNSCALING  QUALITY.
            StretchBlt(hdc, 0, 0, clientWidth, clientHeight, hMemdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

            if (imageEffect == 0)
            {
                SelectObject(hMemdc, hBitmap);
                GetObject(hBitmap, sizeof(BITMAP), &bitmap);//gET BITMAP INFORMATION
                SetStretchBltMode(hdc, COLORONCOLOR);
                StretchBlt(hdc, 0, 0, clientWidth, clientHeight, hMemdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY); 

            }
            else if (imageEffect == 1)
            {
                for (yRow = 0; yRow < resizedWindowHeight; yRow++) 
                {

                  
                        for (xColumn = 0; xColumn < resizedWindowWidth; xColumn++) 
                        {


                            // Get color from the pixel at coordinate (xColumn, yRow)
                            COLORREF originalPixelColor = GetPixel(hdc, xColumn, yRow); 

                            // from original pixel color obtained in above step seperate out the Red Green and Blue components 
                            // using them calcalate dsaturated DR DG and DB

                            unsigned int originalR = GetRValue(originalPixelColor);//we have not used hdc from this point
                            unsigned int originalG = GetGValue(originalPixelColor); 
                            unsigned int originalB = GetBValue(originalPixelColor); 

                            // calculating dsaturated value
                            unsigned int dSaturatedR = (unsigned int)(float)originalR * 0.3f;  
                            unsigned int dSaturatedG = (unsigned int)(float)originalG * 0.59f; 
                            unsigned int dSaturatedB = (unsigned int)(float)originalB * 0.11f; 

                            // Add up dR and dG and dB color component to get final dsaturated color for the pixel
                            unsigned int finalDsaturatedColor = dSaturatedR + dSaturatedG + dSaturatedB; 

                            // set final dsaturated color back to the same pixel or at coordinate xColumn, yRow
                            COLORREF dSaturatedPixelColor = RGB(finalDsaturatedColor, finalDsaturatedColor, finalDsaturatedColor); 
                            SetPixel(hdc, xColumn, yRow, dSaturatedPixelColor);//this will here in wmpaint. 
                              


                        }
                    
                }
            }
            else if (imageEffect == 2)
            {
                for (yRow = 0; yRow < resizedWindowHeight; yRow++) 
                {

                 

                        for (xColumn = 0; xColumn < resizedWindowWidth; xColumn++)
                        {


                            // Get color from the pixel at coordinate (xColumn, yRow)
                            COLORREF originalPixelColor = GetPixel(hdc, xColumn, yRow);

                            // from original pixel color obtained in above step seperate out the Red Green and Blue components 
                            // using them calculate Sephiya SR SG and SB

                            unsigned int originalR = GetRValue(originalPixelColor);  
                            unsigned int originalG = GetGValue(originalPixelColor); 
                            unsigned int originalB = GetBValue(originalPixelColor);  

                            // calculating dsaturated value
                            unsigned int sephiyaR = (unsigned int)(((float)originalR * 0.393f) + ((float)originalG * 0.769f) + ((float)originalB * 0.189f)); 
                            if (sephiyaR > 255)
                            {
                                sephiyaR = 255;// in openGL campling mhantat
                            }
                            unsigned int sephiyaG = (unsigned int)(((float)originalR * 0.349f) + ((float)originalG * 0.686f) + ((float)originalB * 0.168f)); 
                            if (sephiyaG > 255)
                            {
                                sephiyaG = 255;// in openGL campling mhantat
                            }
                            unsigned int sephiyaB = (unsigned int)(((float)originalR * 0.272f) + ((float)originalG * 0.534f) + ((float)originalB * 0.131f)); 
                            if (sephiyaB > 255)
                            {
                                sephiyaB = 255;// in openGL campling mhantat  
                            }



                            // set final dsaturated color back to the same pixel or at coordinate xColumn, yRow
                            COLORREF sephiyaPixelColor = RGB(sephiyaR, sephiyaG, sephiyaB); 
                            SetPixel(hdc, xColumn, yRow, sephiyaPixelColor); 



                        }
                    
                }
            }
            else if (imageEffect == 3) 
            {
                for (yRow = 0; yRow < resizedWindowHeight; yRow++) 
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
            else if (imageEffect == 4)
            {
                // get Pixel color at( pickedPixelXcoord,pickedPixelYcoord)
                COLORREF pickedPixelColorRGB = GetPixel(hdc, pickedPixelXCoord, pickedPixelYCoord);
                             pickedPixelColorR = GetRValue(pickedPixelColorRGB);
                             pickedPixelColorG = GetGValue(pickedPixelColorRGB);
                             pickedPixelColorB = GetBValue(pickedPixelColorRGB);

                //Enter make entry of the picked color in RGB in the colorpicker log file.
                fprintf(gpFile_UserLog, "User picked a color.\n");

                if (gpFile_ColorPickerLog)
                {
                    
                    fprintf(gpFile_ColorPickerLog, "User picked color RGB = (%u,%u,%u)\n", pickedPixelColorR, pickedPixelColorG, pickedPixelColorB);

                }


                if (gpFile_ColorPickerNormalizedLog)
                {

                    float normalizedRed = (float)pickedPixelColorR / 255.0f; 
                    float normalizedGreen = (float)pickedPixelColorG / 255.0f; 
                    float normalizedBlue = (float)pickedPixelColorB / 255.0f; 
                    fprintf(gpFile_ColorPickerNormalizedLog, "User picked color RGB = (%f,%f,%f)\n", normalizedRed, normalizedGreen, normalizedBlue);


                }
                SetDlgItemInt(hwndmodeless, IDC_STATIC_R_VALUE, pickedPixelColorR, FALSE); 
                SetDlgItemInt(hwndmodeless, IDC_STATIC_G_VALUE, pickedPixelColorG, FALSE); 
                SetDlgItemInt(hwndmodeless, IDC_STATIC_B_VALUE, pickedPixelColorB, FALSE); 
                InvalidateRect(GetDlgItem(hwndmodeless, IDC_COLOR_BOX), NULL, TRUE); 

            }
            DeleteDC(hMemdc);

        }
        else
        {
            //if no bitmap is loaded , display default text.
            SetBkColor(hdc, RGB(0, 0, 0));
            SetTextColor(hdc, RGB(0, 255, 0));

            // Default text to display
            if (!userRegistered)
            {
                wsprintf(str, "Please Register first by navigating to Edit Image menu item through Edit menu");

            }
            else
            {
                wsprintf(str, "Open File by navigating to File menu and Open file menu item");

            }
            //Draw text in the window center
            DrawText(hdc, str, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }

        EndPaint(hwnd, &ps);
        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDM_EDIT:
           // DialogBox(hInst, MAKEINTRESOURCE(DATAENTRY), hwnd, MyDlgProc);
            hwndmodeless = CreateDialog(hInst, MAKEINTRESOURCE(DATAENTRY), hwnd, MyDlgProc);
            if (hwndmodeless)
            {
                ShowWindow(hwndmodeless, SW_SHOW); // Show the dialog box
                

            }


            break;
             
        case IDM_APP_ABOUT: 
            DialogBox(hInst, MAKEINTRESOURCE(ABOUTBOX), hwnd, AboutDlgProc); 
            break;

        case IDM_OPEN:
           //Display the Open dialog box when clicked on Open File
            

            if (GetOpenFileName(&ofn) == TRUE) 
            {
                if (hBitmap)// Delete the previous bitmap if it exists
                    DeleteObject(hBitmap);
                
                // Load the selected image
                hBitmap = (HBITMAP)LoadImage(NULL, ofn.lpstrFile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                if (hBitmap == NULL)
                {
                    MessageBox(hwnd, TEXT("Failed to load Image."), TEXT("Error"), MB_ICONERROR | MB_OK);
                }
                else
                {
                    InvalidateRect(hwnd, NULL, TRUE); // TO TRIGGER WM_PAINT TO DISPLAY THE LOADED IMAGE.
                }
                
            }  
            break;


        case IDM_EXIT:
            DestroyWindow(hwnd);
            break;

        }

        break;

    case WM_SIZE: 
        //Get the Client area Rectangle of our window
        GetClientRect(hwnd, &rect);
        SetWindowPos(hwnd, HWND_TOP, 0, 0, windowWidth, windowHeight, SWP_NOMOVE | SWP_NOZORDER);
        resizedWindowWidth = LOWORD(lParam); 
        resizedWindowHeight = HIWORD(lParam); 
       
        break;

    case WM_LBUTTONDOWN:
        pickedPixelXCoord = GET_X_LPARAM(lParam);
        pickedPixelYCoord = GET_Y_LPARAM(lParam);

        // Trigger WM_PAINT message to repaint image and to get pixel color at (pickedPixelXCoord, pickedPixelYCoord)
        InvalidateRect(hwnd, NULL, TRUE);
        break;

    case WM_KEYDOWN:
        switch (wParam) {

        case VK_SPACE: 
            InvalidateRect(hwnd, NULL, TRUE); 
            break;
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;
        }

        break;

    case WM_DESTROY:
        CloseAllLogFiles();
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
    HBRUSH hDlgBrush;

    HWND disableDesaturationApplyEffect;
    HWND disableSepiaApplyEffect;
    HWND disableNegativeApplyEffect;
    HWND disableDesaturationResetEffect;
    HWND disableSepiaResetEffect;
    HWND disableNegativeResetEffect;
    disableDesaturationApplyEffect = GetDlgItem(hDlg, ID_APPLY_DESATURATION_EFFECT);
    disableSepiaApplyEffect = GetDlgItem(hDlg, ID_APPLY_SEPIA_EFFECT);
    disableNegativeApplyEffect = GetDlgItem(hDlg, ID_APPLY_NEGATIVE_EFFECT);
    disableDesaturationResetEffect = GetDlgItem(hDlg, ID_RESET_DESATURATION_EFFECT);
    disableSepiaResetEffect = GetDlgItem(hDlg, ID_RESET_SEPIA_EFFECT);
    disableNegativeResetEffect = GetDlgItem(hDlg, ID_RESET_NEGATIVE_EFFECT);


    switch (iMsg)
    {
    case WM_INITDIALOG:
        EnableWindow(disableDesaturationApplyEffect, FALSE); 
        EnableWindow(disableSepiaApplyEffect, FALSE); 
        EnableWindow(disableNegativeApplyEffect, FALSE); 
        EnableWindow(disableDesaturationResetEffect, FALSE); 
        EnableWindow(disableSepiaResetEffect, FALSE); 
        EnableWindow(disableNegativeResetEffect, FALSE); 

        EnableWindow(GetDlgItem(hDlg, IDG_IMAGE_EDITOR), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDG_COLOR_PICKER), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDG_DESATURATION), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDG_SEPIA), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDG_NEGATIVE), FALSE);

        EnableWindow(GetDlgItem(hDlg, IDR_IMAGE_EFFECTS), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDR_PICK_COLOR), FALSE);

        EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_PICKED_COLOR), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDC_STATIC_R_VALUE), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDC_STATIC_G_VALUE), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDC_STATIC_B_VALUE), FALSE); 
        EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_RTEXT), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_GTEXT), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_BTEXT), FALSE);
        EnableWindow(GetDlgItem(hDlg, IDC_LOG), FALSE); 
        EnableWindow(GetDlgItem(hDlg, IDC_NOR_LOG), FALSE);

        if (gpFile_UserLog != NULL)
        {
            EnableWindow(GetDlgItem(hDlg, IDR_IMAGE_EFFECTS), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDR_PICK_COLOR), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDD_REGISTER_DIALOG), FALSE);

        } 
      return (TRUE);

    case WM_CTLCOLORDLG:
        hDlgBrush = CreateSolidBrush(RGB(193, 202, 214)); 
        return ((BOOL)hDlgBrush);

    case WM_DRAWITEM: 
    {
        LPDRAWITEMSTRUCT lpdis = (LPDRAWITEMSTRUCT)lParam;   
         
        if (lpdis->CtlID == IDC_COLOR_BOX)  
        {
            // Fill the box with the picked color
            HBRUSH hBrush = CreateSolidBrush(RGB(pickedPixelColorR, pickedPixelColorG, pickedPixelColorB));   
            FillRect(lpdis->hDC, &lpdis->rcItem, hBrush);  
            DeleteObject(hBrush);    
            return TRUE; 
        }
    }
    break;



    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDR_IMAGE_EFFECTS:
            EnableWindow(disableDesaturationApplyEffect, TRUE);
            EnableWindow(disableSepiaApplyEffect, TRUE);
            EnableWindow(disableNegativeApplyEffect, TRUE);
            EnableWindow(disableDesaturationResetEffect, TRUE);
            EnableWindow(disableSepiaResetEffect, TRUE); 
            EnableWindow(disableNegativeResetEffect, TRUE); 

            EnableWindow(GetDlgItem(hDlg, IDG_IMAGE_EDITOR), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDG_COLOR_PICKER), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDG_DESATURATION), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDG_SEPIA), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDG_NEGATIVE), TRUE); 

            CheckDlgButton(hDlg, IDR_IMAGE_EFFECTS, BST_UNCHECKED);
            CheckDlgButton(hDlg, IDR_PICK_COLOR, BST_UNCHECKED);

            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_PICKED_COLOR), FALSE); 
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_R_VALUE), FALSE);  
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_G_VALUE), FALSE); 
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_B_VALUE), FALSE); 

            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_RTEXT), FALSE);
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_GTEXT), FALSE); 
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_BTEXT), FALSE);
            EnableWindow(GetDlgItem(hDlg, IDC_LOG), FALSE);
            EnableWindow(GetDlgItem(hDlg, IDC_NOR_LOG), FALSE);

            imageEffectChecked = TRUE;
            if (imageEffectChecked)
            {
                CheckDlgButton(hDlg, IDR_IMAGE_EFFECTS, BST_CHECKED); 
                CheckDlgButton(hDlg, IDR_PICK_COLOR, BST_UNCHECKED);
            }
            else
            {
                CheckDlgButton(hDlg, IDR_IMAGE_EFFECTS, BST_UNCHECKED);
                CheckDlgButton(hDlg, IDR_PICK_COLOR, BST_CHECKED);
            }

            break;

        case IDR_PICK_COLOR: // Pick Color selected
            EnableWindow(disableDesaturationApplyEffect, FALSE); 
            EnableWindow(disableSepiaApplyEffect, FALSE); 
            EnableWindow(disableNegativeApplyEffect, FALSE); 
            EnableWindow(disableDesaturationResetEffect, FALSE); 
            EnableWindow(disableSepiaResetEffect, FALSE); 
            EnableWindow(disableNegativeResetEffect, FALSE); 

            EnableWindow(GetDlgItem(hDlg, IDG_IMAGE_EDITOR), FALSE); 
            EnableWindow(GetDlgItem(hDlg, IDG_COLOR_PICKER), TRUE); 
            EnableWindow(GetDlgItem(hDlg, IDG_DESATURATION), FALSE);
            EnableWindow(GetDlgItem(hDlg, IDG_SEPIA), FALSE); 
            EnableWindow(GetDlgItem(hDlg, IDG_NEGATIVE), FALSE); 

            CheckDlgButton(hDlg, IDR_IMAGE_EFFECTS, BST_UNCHECKED);
            CheckDlgButton(hDlg, IDR_PICK_COLOR, BST_UNCHECKED); 

            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_PICKED_COLOR), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_R_VALUE), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_G_VALUE), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_B_VALUE), TRUE);

            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_RTEXT), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_GTEXT), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDC_STATIC_TEXT_BTEXT), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDC_LOG), TRUE);
            EnableWindow(GetDlgItem(hDlg, IDC_NOR_LOG), TRUE); 

            // Enable Color Picker controls and disable  Image Editor.
            imageEffect = 4;

            EnableWindow(GetDlgItem(hDlg, IDG_IMAGE_EDITOR), FALSE);   
            EnableWindow(GetDlgItem(hDlg, IDG_COLOR_PICKER), TRUE); 

            imageEffectChecked = FALSE;
            if (!imageEffectChecked)
            {
                CheckDlgButton(hDlg, IDR_IMAGE_EFFECTS, BST_UNCHECKED); 
                CheckDlgButton(hDlg, IDR_PICK_COLOR, BST_CHECKED); 
            }
            else
            {
                CheckDlgButton(hDlg, IDR_IMAGE_EFFECTS, BST_CHECKED); 
                CheckDlgButton(hDlg, IDR_PICK_COLOR, BST_UNCHECKED); 
            }

            break;

        case IDD_REGISTER_DIALOG:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_REGISTER_DIALOG), hDlg, RegisterDlgProc);
            if (userRegistered)
            {
                EnableMenuItem(hMenu, IDM_OPEN, MF_BYCOMMAND | MF_ENABLED);
                EnableWindow(GetDlgItem(hDlg, IDD_REGISTER_DIALOG), FALSE);

            }
            break;

        case ID_APPLY_DESATURATION_EFFECT:
            MessageBox(hDlg, "Desaturation clicked", "DEBUG", MB_OK); 
            imageEffect = 1;
            fprintf(gpFile_UserLog, "User Applied Desaturation Effect. \n");
            InvalidateRect(hwnd, NULL, TRUE);
            break;

        case ID_APPLY_SEPIA_EFFECT:
            imageEffect = 2; 
            fprintf(gpFile_UserLog, "User Applied Sepia Effect. \n"); 
            InvalidateRect(hwnd, NULL, TRUE);
            break;

        case ID_APPLY_NEGATIVE_EFFECT:
            imageEffect = 3;
            fprintf(gpFile_UserLog, "User Applied Negative Effect. \n");
            InvalidateRect(hwnd, NULL, TRUE);
            break;

        case ID_RESET_DESATURATION_EFFECT:
            imageEffect = 0; 
            fprintf(gpFile_UserLog, "User Reset the Image.\n"); 
            InvalidateRect(hwnd, NULL, TRUE);
            break;

        case ID_RESET_SEPIA_EFFECT:
            imageEffect = 0;
            fprintf(gpFile_UserLog, "User Reset the Image.\n");
            InvalidateRect(hwnd, NULL, TRUE);

            break;

        case ID_RESET_NEGATIVE_EFFECT:
            imageEffect = 0;
            fprintf(gpFile_UserLog, "User Reset the Image.\n");
            InvalidateRect(GetParent(hDlg), NULL, TRUE); 
            break;

        case IDC_LOG:
            CheckDlgButton(hDlg, IDC_LOG, BST_CHECKED);
            CreateColorPickerLogFile(firstName, lastName);
            InvalidateRect(hwnd, NULL, TRUE); 
            break;

        case IDC_NOR_LOG:
            CheckDlgButton(hDlg, IDC_NOR_LOG, BST_CHECKED);
            //CreateNormalizedColorPickerLogFile(firstName, lastName); 
            break;

        case IDOK: 
            DestroyWindow(hDlg);

            break;

        case IDCANCEL:
            EndDialog(hDlg, IDCANCEL);
            InvalidateRect(GetParent(hDlg), NULL, TRUE); // FORCE REPAINT OF PARENT WINDOW.
            break;

        case IDM_APP_ABOUT:
            DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(ABOUTBOX), hDlg, AboutDlgProc);
            DestroyWindow(hDlg);

            break;



        }
        return(TRUE);

    case WM_CLOSE:
        DestroyWindow(hDlg);
        // dialog close event.
        break;
    }
    return (FALSE);
}

// About Dialog Box Procedure
INT_PTR CALLBACK AboutDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_INITDIALOG:
        // hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(ABOUT_ICON));
       // if (hIcon != NULL)
       // {
         //   SendDlgItemMessage(hDlg, dhPICON, STM_SETICON, (WPARAM)hIcon, 0);
        //}
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            EndDialog(hDlg, 0); 
            break;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            return TRUE;


        }
        break;

    case WM_CTLCOLORDLG: 
        hDlgBrush = CreateSolidBrush(RGB(0, 0, 0)); 

        return((INT_PTR)hDlgBrush);  

    case WM_CTLCOLORSTATIC:
        hDlgBrush = CreateSolidBrush(RGB(0, 0, 0));
        SetBkColor((HDC)wParam, RGB(0, 0, 0));
        SetTextColor((HDC)wParam, RGB(255, 254, 165));
        return((INT_PTR)hDlgBrush); 

          
    case WM_CLOSE: 
        EndDialog(hDlg, 0);  // dialog close event. 
        break;

    }
    return FALSE; // Not processed.

}

INT_PTR CALLBACK RegisterDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Variable declaration
    HWND hFirstName = GetDlgItem(hDlg, IDC_FIRST_NAME);
    HWND hMiddleName = GetDlgItem(hDlg, IDC_MIDDLE_NAME);
    HWND hLastName = GetDlgItem(hDlg, IDC_LAST_NAME);
    HWND hRegisterButton = GetDlgItem(hDlg, ID_REGISTER_BUTTON);

    static BOOL isFirstNameValid = FALSE; 
    static BOOL isMiddleNameValid = FALSE;
    static BOOL isLastNameValid = FALSE;

    switch (iMsg)
    {
    case WM_INITDIALOG:
        EnableWindow(hRegisterButton, FALSE); // Disable RegisterButton Initially. 
        // force redraw of static text lables to apply default color
        InvalidateRect(GetDlgItem(hDlg, IDL_FIRST_TEXT), NULL, TRUE);
        InvalidateRect(GetDlgItem(hDlg, IDL_MIDDLE_TEXT), NULL, TRUE);
        InvalidateRect(GetDlgItem(hDlg, IDL_LAST_TEXT), NULL, TRUE);
        break;

    case WM_COMMAND: 
        switch (LOWORD(wParam))
        {
        case ID_REGISTER_BUTTON: 
            // proceed with registration logic
            GetWindowText(hFirstName, firstName, sizeof(firstName) / sizeof(TCHAR));
            GetWindowText(hMiddleName, middleName, sizeof(middleName) / sizeof(TCHAR));
            GetWindowText(hLastName, lastName, sizeof(lastName) / sizeof(TCHAR));

            CreateUserLogFile(firstName, lastName);
            //show configuration message box
            MessageBox(hDlg, TEXT("USER REGISTERED SUCCESSFULLY"), TEXT("SUCCESS"), MB_OK);
            userRegistered = TRUE;
            InvalidateRect(GetParent(hDlg), NULL, TRUE);
            EndDialog(hDlg, ID_REGISTER_BUTTON);
            break;

        case IDC_FIRST_NAME:
        case IDC_MIDDLE_NAME:
        case IDC_LAST_NAME:
        case EN_KILLFOCUS:
        {
            //VALIDATE EACH NAME FILED
            TCHAR name[100];
            GetWindowText((HWND)lParam, name, sizeof(name) / sizeof(TCHAR));
            BOOL isValid = isValidName(name);

            //update validation flags and text color
            switch (LOWORD(wParam))
            {
            case IDC_FIRST_NAME:
                isFirstNameValid = isValid;
                break;

            case IDC_MIDDLE_NAME:
                isMiddleNameValid = isValid;
                break;
                
            case IDC_LAST_NAME:
                isLastNameValid = isValid;
                break;

            }

            //Enable Register button only if all fields are valid
            EnableWindow(hRegisterButton, isFirstNameValid && isMiddleNameValid && isLastNameValid);

            // Fprce redraw of static text labels to update their color
            InvalidateRect(GetDlgItem(hDlg, IDL_FIRST_TEXT), NULL, TRUE);
            InvalidateRect(GetDlgItem(hDlg, IDL_MIDDLE_TEXT), NULL, TRUE);
            InvalidateRect(GetDlgItem(hDlg, IDL_LAST_TEXT), NULL, TRUE);
        }
        break;
        
        }
        break;

    case WM_CTLCOLORDLG:
        hDlgBrush = CreateSolidBrush(RGB(176, 255, 100));
        return ((INT_PTR)hDlgBrush);

    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam; 
        HWND hwndStatic = (HWND)lParam;
        hDlgBrush = CreateSolidBrush(RGB(176, 255, 100));
        SetBkColor((HDC)wParam, RGB(176, 255, 100));
        // Set text color based on validation

        if (hwndStatic == GetDlgItem(hDlg, IDL_FIRST_TEXT)) 
        {
            if (isFirstNameValid)
                SetTextColor(hdcStatic, RGB(0, 0, 0));
            else
                SetTextColor(hdcStatic, RGB(255, 0, 0)); 

        }

        if (hwndStatic == GetDlgItem(hDlg, IDL_MIDDLE_TEXT)) 
        {
            if (isMiddleNameValid)
                SetTextColor(hdcStatic, RGB(0, 0, 0)); 
            else
                SetTextColor(hdcStatic, RGB(255, 0, 0));   

        }     

        if (hwndStatic == GetDlgItem(hDlg, IDL_LAST_TEXT)) 
        {
            if (isLastNameValid) 
                SetTextColor(hdcStatic, RGB(0, 0, 0));
            else
                SetTextColor(hdcStatic, RGB(255, 0, 0));//red if invalid

        }

        return ((INT_PTR)hDlgBrush);



    }
    break;

    case WM_CLOSE:
        EndDialog(hDlg, 0);
        break;

    case WM_DESTROY:
        //CLEAN UP BRUSHES
        //DeleteObject(hDlgBrush);
      
        break;


    }
    return(FALSE); // NOT PROCESSED

}

BOOL isValidName(const TCHAR* name)
{
    // CHECK if the name is empty
    if (name == NULL || *name == 0)
    {
        return(FALSE);

    }

    // check if all characters are letters or spaces
    while (*name)
    {
        if (!isalpha(*name) && *name != ' ') // check if character is not a letter of space
        {
            return (FALSE);
        }
        name++;

    }
    return (TRUE); // VALID NAME
}

void CreateUserLogFile(const char* firstName, const char* surname)
{
    SYSTEMTIME st; // declare the systemtime variable

    // Get current local time
    GetLocalTime(&st); // This fills 'st' with current local system time

    char logFileName[100];
    char timestamp[20]; // Buffer to hold timestamp

    //Format  the timestamp as DDMMYY-HHMMSS
    wsprintf(timestamp, "%02d%02d%04d-%02d%02d%02d", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);

    // generate the log file name using the first name , surname and timestamp

    wsprintf(logFileName, "%s%s-UserLog-%s.txt", firstName, surname, timestamp);

    // open the log file for writing 
    gpFile_UserLog = fopen(logFileName, "w");
    if (gpFile_UserLog == NULL)
    {
        MessageBox(NULL, "Log file not created", "Userlog Error", MB_OK | MB_ICONERROR);
        return;
    }

    // Log Common Details
    fprintf(gpFile_UserLog, "Register User Name:%s %s\n", firstName, surname);
    fprintf(gpFile_UserLog, "User Registration Date: %02d/%02d/%04d\n", st.wDay, st.wMonth, st.wYear); 
    fprintf(gpFile_UserLog, "User Registration Date: %02d:%02d:%02d\n", st.wHour, st.wMinute, st.wSecond);

}

void CreateColorPickerLogFile(const char* firstName, const char* surname)
{
    SYSTEMTIME st; // declare the systemtime variable 

    // Get current local time
    GetLocalTime(&st); // This fills 'st' with current local system time 

    char colorPickerlogFileName[100];
    char timestamp[20]; // Buffer to hold timestamp
    
    //Format  the timestamp as DDMMYY-HHMMSS
    wsprintf(timestamp, "%02d%02d%04d-%02d%02d%02d", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond); 

    // generate the log file name using the first name , surname and timestamp

    wsprintf(colorPickerlogFileName, "%s%s-ColorPicker-%s.txt", firstName, surname, timestamp);

    // open the log file for writing 
    gpFile_ColorPickerLog = fopen(colorPickerlogFileName, "w");
    if (gpFile_ColorPickerLog == NULL)
    {
        MessageBox(NULL, "color picker Log file not created", "Userlog Error", MB_OK | MB_ICONERROR);
        return;
    }

    // Log Common Details
    fprintf(gpFile_ColorPickerLog, "Register User Name:%s %s\n", firstName, surname); 
    fprintf(gpFile_ColorPickerLog, "User Registration Date: %02d/%02d/%04d\n", st.wDay, st.wMonth, st.wYear);
    fprintf(gpFile_ColorPickerLog, "User Registration Date: %02d:%02d:%02d\n", st.wHour, st.wMinute, st.wSecond);
}

void CloseAllLogFiles()
{
    if (gpFile_UserLog)
    {
        SYSTEMTIME stExitTime;

        GetLocalTime(&stExitTime);

        fprintf(gpFile_UserLog, "Program exited at : %02d/%02d/%04d %02d:%02d:%02d\n", stExitTime.wDay, stExitTime.wMonth, stExitTime.wYear, stExitTime.wHour, stExitTime.wMinute, stExitTime.wSecond);

        fprintf(gpFile_UserLog, "Program Terminated Successfully.\n");
        fclose(gpFile_UserLog); //close the user log file
        gpFile_UserLog = NULL;

    }

    if (gpFile_ColorPickerLog)
    {
        fclose(gpFile_ColorPickerLog); //close the user log file
        gpFile_ColorPickerLog = NULL;
    }    

    if (gpFile_ColorPickerNormalizedLog)
    {
        fclose(gpFile_ColorPickerNormalizedLog); //close the user log file
        gpFile_ColorPickerNormalizedLog = NULL;
    }
}

