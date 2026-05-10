#include<windows.h>

//defining dll entrypoint function
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	//code
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;

    }
	return(TRUE);
}

//defining the exportable function makesqure
int MakeCube(int num)
{
	//function prototype
	void CheckNumber(int);

	//code
	CheckNumber(num);
	return(num * num * num);

}

//defining internal usage function checknumber.
void CheckNumber(int num)
{
	//code
	if (num < 0)
	{
		MessageBox(NULL, TEXT("Number is negative"), TEXT("Message"), MB_OK);
	}
}
