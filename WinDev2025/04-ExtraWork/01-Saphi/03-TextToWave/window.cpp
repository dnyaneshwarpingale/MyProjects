// Win32 headers
#define UNICODE
#include <windows.h>

#include <sapi.h> //speech application programming interface.
#include <sphelper.h> // sapi helper functions

#include "Window.h"

//declaring interface pointers.
ISpVoice* pISpVoice = NULL;
IEnumSpObjectTokens* pIEnumSpObjectTokens = NULL;  // ENUMARATE LIST OF SYSTEM VOICES.
ISpObjectToken* pIspObjectToken = NULL; // token actual info about voices.
ISpStream* pISpStream = NULL;

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
    //variable declarations
    HRESULT hr = S_OK; 

    hr = CoInitialize(NULL); 
    if (FAILED(hr))
    {
        MessageBox(NULL, TEXT("co Initilized failed"), TEXT("COM ERROR"), MB_OK | MB_ICONERROR); 
        exit(0); 
    }
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

    //Uninitializing the COM engine.
    CoUninitialize();  

    return ((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Code
    //varible declaration
   
    unsigned int x = 0;
    unsigned int y = 0;
    //functions
    void  SafeInterfaceRelease(void);

    //variable declarations
    HRESULT hr = S_OK;
    ULONG numVoices = 0L;
    WCHAR* voiceNameDescriptionString = NULL;
    CSpStreamFormat audioFormat;
    wchar_t text[] = L"Hello Dnyaneshwar Haribhau Pingale. This is your first sapi program. Congratulations!!.";
    TCHAR str[255];
     

    switch (iMsg)
    {
    case WM_CREATE:
        hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void**)&pISpVoice);
        if (FAILED(hr))
        {
            MessageBox(hwnd, TEXT("NOT LOADED SPVOICE LIBRARRY"), TEXT("COM ERROR"), MB_ICONERROR | MB_OK);
            DestroyWindow(hwnd);
        }

        break;

    case WM_LBUTTONDOWN:
        //Enumarate or get list of system voices.
        hr = SpEnumTokens(SPCAT_VOICES, NULL, NULL, &pIEnumSpObjectTokens);  // it is an sapi helper functions.//Ienumspobjecttokns  it is list of interfaces of ispobjecttoken pointers
        if (FAILED(hr))
        {
            MessageBox(hwnd, TEXT("spEnumTokens Failed"), TEXT("COM ERROR"), MB_ICONERROR | MB_OK);
            DestroyWindow(hwnd);
        }

        //from the list of voices obtain in the above step get the total no. of available system voices.
        hr = pIEnumSpObjectTokens->GetCount(&numVoices);
        if (FAILED(hr))
        {
            MessageBox(hwnd, TEXT("GET COUNT failed"), TEXT("COM ERROR"), MB_ICONERROR | MB_OK);
            DestroyWindow(hwnd);
        }
        wsprintf(str, TEXT("No of available system voices = %ld", numVoices));
        MessageBox(hwnd, str, TEXT("VOices"), MB_OK | MB_ICONINFORMATION);

        //set audio file wave format.
        audioFormat.AssignFormat(SPSF_44kHz16BitStereo);

        //By default audio stream goes to the default output device that is the speaker.
        //Now we want bind the audio stream to wave file.
        hr =SPBindToFile(TEXT("DHP_AUDIOMESSAGE.WAV"), SPFM_CREATE_ALWAYS,&pISpStream,&audioFormat.FormatId(),audioFormat.WaveFormatExPtr()); 
        if (FAILED(hr))
        {
            MessageBox(hwnd, TEXT("SPBINDTOFILE failed"), TEXT("COM ERROR"), MB_ICONERROR | MB_OK);
            DestroyWindow(hwnd);
        }
        
        //set audio output pispstream instead of default audio speaker.
        hr = pISpVoice->SetOutput(pISpStream, FALSE); 
        if (FAILED(hr))
        {
            MessageBox(hwnd, TEXT("SET OUTPUT failed"), TEXT("COM ERROR"), MB_ICONERROR | MB_OK);
            DestroyWindow(hwnd);
        }


        while (numVoices > 0)
        {
           // get the next voice token from pIenumspobjecttokens
            pIEnumSpObjectTokens->Next(1, &pIspObjectToken, NULL);

            //from the voice token obtained above extract the name of the voice.
            SpGetDescription(pIspObjectToken, &voiceNameDescriptionString);

            //Display above obtained name of the voice In message box
            MessageBox(hwnd, voiceNameDescriptionString, TEXT("VOICE NAME"), MB_OK | MB_ICONINFORMATION);

            //Now Set the voice of the above obtained token as current voice.
            pISpVoice->SetVoice(pIspObjectToken);
            //Convert Text to speech in the voice set in the above step.
            pISpVoice->Speak(text, 0, NULL); 

            numVoices--;

            if (pIspObjectToken)
            {
                pIspObjectToken->Release();
                pIspObjectToken = NULL; 
            }
        }


        
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

void SafeInterfaceRelease(void)
{
    if (pISpStream)
        pISpStream->Release();
    pISpStream = NULL;

    if (pIspObjectToken)
        pIspObjectToken->Release();

    pIspObjectToken = NULL;

    if (pIEnumSpObjectTokens)
        pIEnumSpObjectTokens->Release();

    pIEnumSpObjectTokens = NULL; 

    if (pISpVoice)
        pISpVoice->Release();

        pISpVoice = NULL;
}