#include <windows.h> //Aadhy header file and all function or struct MSG declaration or prototype

//Global callback function declaration 
LRESULT CALLBACK WndProc(HWND , UINT, WPARAM, LPARAM); // long type cha result(LRESULT) is typedef longptr is typedef of long 

//CALLBACK is calling convection  //COF-common object format. callback is typedef of __stdCall(parameter right to left jatat and function itself clear its stack) -->> typedef of __pascal

//HWND(hanadle to window) is typedef of handle is typdef of pVoid is typeDef of Void*
// UINT is typedef of unsigned int 
//WPARAM (word (16-bit volue) parameter  ) is typedef WORD is typedef UINTPTR is typedef of unsigned short
//LPARAM (Long parameter ) is typedef of longptr is typedef of long

//macro #define STRICT --> these macro says you cannot use directly c data type

//Entry Point function 
//
int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpszCmdLine , int iCmdShow)

{

	//WINAPI is typedef of __stdCall 
	//HINSTANCE (handle to instance ) is typedef of HANDLE is typedef of pVoid is typedef of Void* (pointer) is 32-bit unsigned integer iy is an opec pointer 
	//HANDLE is unsigned 32-bit integer unique id 
	//INSTANCE HE CONCEPT WINDOWS MADHE VAPARALI JATE . UNIX /LINUX MADHE INSTANCE TERM VAPARALI JAT NAHI .HINSTANCE IS UNIQUE ID OF PROCESS INSTANCE
    //hPrevInstance is during cooperative multitasking used(1985-1993).. // now its not usable now its null by os.// its keep for leagacy and backward compatibility
	//LPSTR (long pointer to string ) is typedef of CHAR *
    // CommandLine argument is parameter given to main fn by cmdline 
	//CmdShow ==>commandwindow ti kashi dakhvli geli pahije(minimize,normal,maximize)
	
		//Variable Declarations
		WNDCLASSEX wndclass;
		TCHAR szAppName[] = TEXT("DHP_WINDOW");
		HWND hwnd;
		MSG msg;

		//code
		memset((void*)&wndclass, 0,sizeof(WNDCLASSEX));

		//Initializing Window class
		wndclass.cbSize = sizeof(WNDCLASSEX); 
		wndclass.style = CS_HREDRAW | CS_VREDRAW;
		wndclass.cbClsExtra = 0; 
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = hInstance;
		wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndclass.hIcon = LoadIcon(NULL , IDI_APPLICATION);
		wndclass.hIconSm = LoadIcon(NULL , IDI_APPLICATION);
		wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndclass.lpfnWndProc = WndProc;
		wndclass.lpszClassName = szAppName;
		wndclass.lpszMenuName = NULL;

		//Register the above Window class 
		RegisterClassEx(&wndclass);

		//create the window
		hwnd=CreateWindow(szAppName,
		TEXT("DHP:MY FIRST WINDOW"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL

		);

		//Show the Window
		ShowWindow(hwnd,iCmdShow);

		//Update the Window
		UpdateWindow(hwnd);

		//Messageloop 
		while(GetMessage(&msg, NULL, 0 ,0))
		{
			TranslateMessage(&msg);
			DidpatchMessage(&msg);
		}

		return((int)msg.wParam);

}

//WindowProcedure
LRESULT CALLBACK WndProc(HWND hwnd , UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Variable declarations

	//code
	switch(iMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
        
		default:
			break;
	}

	return(DefWindowProc(hwnd,iMsg,wParam,lParam));

}

