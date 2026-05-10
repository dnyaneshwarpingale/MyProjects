//With respect to classfactory dll server with reg file.cpp there are total 14  changes in automationserver.cpp and they are mark at appropriate locations.
#define UNICODE 
#include<windows.h>
#include<stdio.h>   //for swprintf_s() //change no:1 next batch la he fuction thod aadhi ghyach aahe he madam la sangaych aahe.
#include"AutomationServer.h"

//CHANGENO2 ONLY ONE INTERFACE INHERITED.
//class declarations
class CMyMath : public IMyMath  //Csumsubtract is kamgar adda or worker class 
{
private:
	long m_cRef;
	//chnageno:3 declaring itypeinfo intrface pointer in coclass private data members. this is the microsofts define  interface 
	ITypeInfo* m_pITypeInfo;

public:
	//constructor method declarations
	CMyMath(void);

	//destructor method declarations
	~CMyMath(void);

	//IUnknown specific method declarations (inherited)//great grand father IUnknwn
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//change4a declareing functions of grand father IDispatch.
	//IDispatch specific method declarations (inherited)//grand father IDispatch
	HRESULT __stdcall GetTypeInfoCount(UINT*);
	HRESULT __stdcall GetTypeInfo(UINT, LCID, ITypeInfo**);
	HRESULT __stdcall GetIDsOfNames(REFIID, LPOLESTR*, UINT, LCID, DISPID*);//LCID=>local id language independent. lpolestr =>longpointer string.  dispid==>dispatchId.
	HRESULT __stdcall Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT*, EXCEPINFO*, UINT*);//dispparams ==>dispatchparameters. variant==>its for take return value. and for catch exception =>ecepinfo. and error come to catch exception 8th parameter.


	//FATHERS METHOD DECLARATIONS
	//Isum specific method declarations (inherited)
	HRESULT __stdcall SumOfTwoIntegers(int, int, int*);

	//ISubtract specific method declarations (inherited)
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);

	//changeno:4b 

	HRESULT __stdcall InitInstance(void);




};

class CMyMathClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:
	//constructor method declarations
	CMyMathClassFactory(void);

	//destructor method declarations
	~CMyMathClassFactory(void);

	//IUnknown specific method declarations (inherted)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory specific method declarations (inherited)
	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);


};

//changeNo:5//declaring typelibrary guid in cpp global varible.// {B5C04196-02DE-4A18-8D55-6C6D59DE525C}

const GUID LIBID_AutomationServer = { 0xb5c04196, 0x2de, 0x4a18, 0x8d, 0x55, 0x6c, 0x6d, 0x59, 0xde, 0x52, 0x5c };


//global variable declarations
long glNumberOfActiveComponents = 0; //number of active components
long glNumberOfServerLocks = 0; //number of locks on this dll

//DllMain
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID Reserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	
	case DLL_PROCESS_DETACH:
		break;

	}

	return(TRUE);

}

//Implementation of CSumSubtract's Constructor
CMyMath::CMyMath(void)
{ 
	//hardcoded initialization to anticipate possible possible failure of QueryInterface()
	m_cRef = 1;
	//CHANGEnO6A:INITIALIZING MPITYPEINFO TO NULL.
	m_pITypeInfo = NULL;

	InterlockedIncrement(&glNumberOfActiveComponents);//increment global counter
}

//Implementation of CSumSubtract's Destructor Method 
CMyMath::~CMyMath(void)
{ 
	InterlockedDecrement(&glNumberOfActiveComponents);//decrement global counter
	//changeno:6b..
	if (m_pITypeInfo)
	{
        m_pITypeInfo->Release(); 
		m_pITypeInfo = NULL; 
	
	}

}

//Implementation of CSumSubtract's IUnknown's Methods
HRESULT CMyMath::QueryInterface(REFIID riid, void** ppv)
{
	//change no:7.elseif block for iididispatch

	if (riid == IID_IUnknown)
		*ppv = static_cast<IMyMath*>(this); 
	else if (riid == IID_IDispatch)
		*ppv = static_cast<IMyMath*>(this); 
	else if (riid == IID_IMyMath)
		*ppv = static_cast<IMyMath*>(this);
	else
	{
		*ppv = NULL;
		return (E_NOINTERFACE);
	}

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();

	return(S_OK);

}

ULONG CMyMath::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef); 

}

ULONG CMyMath::Release(void)
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return(0);

	}

	return(m_cRef);

}

//change no:8 implementation of the IDispatch 's method GetTyoeInfoCount

HRESULT CMyMath::GetTypeInfoCount(UINT* pCountTypeInfo)
{
	//as we have type library it is 1 , else 0
	*pCountTypeInfo = 1;

	return(S_OK);

}

//changeno:9

HRESULT CMyMath::GetTypeInfo(UINT iTypeInfo, LCID lcid, ITypeInfo** ppITypeInfo)//index of typeinfo.
{
	*ppITypeInfo = NULL;
	if (iTypeInfo != 0)
		return(DISP_E_BADINDEX);

	m_pITypeInfo->AddRef();

	*ppITypeInfo = m_pITypeInfo;

	return(S_OK);


}

//changeno:10
HRESULT CMyMath::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId)
{
	return(DispGetIDsOfNames(m_pITypeInfo, rgszNames, cNames, rgDispId));//its coms automation (oleaut32.dll) helper function// like cocreateinstance , coinitialize 
}

//change:11
HRESULT CMyMath::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
	//variable declarations
	HRESULT hr = S_OK;

	hr = DispInvoke(this,
		m_pITypeInfo,
		dispIdMember,
		wFlags,
		pDispParams,
		pVarResult,
		pExcepInfo,
		puArgErr);

	return(hr);
}

//change no:12

HRESULT CMyMath::InitInstance(void)
{
	//function declarations
	void ComErrorDescriptionString(HWND, HRESULT);

	//variable declarations
	HRESULT hr = S_OK;
	ITypeLib* pITypeLib = NULL; 

	//CODE
	if (m_pITypeInfo == NULL)
	{
		hr = LoadRegTypeLib(LIBID_AutomationServer,
			1, 0,//major version, minor version
			0x00,
			&pITypeLib);
		if (FAILED(hr))
		{
			ComErrorDescriptionString(NULL, hr);
			return(hr);
		}
		
		hr = pITypeLib->GetTypeInfoOfGuid(IID_IMyMath, &m_pITypeInfo);

		if (FAILED(hr))
		{
			ComErrorDescriptionString(NULL, hr);
			pITypeLib->Release();
			return(hr);
		}

		pITypeLib->Release();  
		pITypeLib = NULL;

	}
	return(S_OK);

}

//Implementation Of ISum's Methods
HRESULT CMyMath::SumOfTwoIntegers(int num1, int num2, int* pSum)
{
	*pSum = num1 + num2;

	return(S_OK);
}

//Implementation of ISubtract's Methods
HRESULT CMyMath::SubtractionOfTwoIntegers(int num1, int num2, int* pSubtract)
{
	*pSubtract = num1 - num2;
	return(S_OK);
}

//Implementation of CSumSubtractClassFactory's Constructor Method
CMyMathClassFactory::CMyMathClassFactory(void)
{
	m_cRef = 1; //hardcoded initialization to antcipate possible failure of QueryInterface()
}

//Implementation of CSumSubtractClassFactory's Destructor method
CMyMathClassFactory::~CMyMathClassFactory(void)
{
	//no code
}

//Implementation of CSumSubtractCassFactory's IClassFactory's IUnknown's Methods
HRESULT CMyMathClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
		*ppv = static_cast<IClassFactory*>(this);
	else if (riid == IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return(S_OK);

}

ULONG CMyMathClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CMyMathClassFactory::Release(void) 
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return(0);

	}

	return(m_cRef);

}

//Implentation of CSumSubtractClassFactory's ICassFactory's Methods
HRESULT CMyMathClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//variable declarations
	CMyMath* pCMyMath = NULL;
	HRESULT hr = S_OK;

	//code
	if (pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);

	// create the instance of component i.e. of CSumSubtract class
	pCMyMath = new CMyMath;  //call to constructor to get memory. 
	 
	if (pCMyMath == NULL) 
		return(E_OUTOFMEMORY);     

	//changeNo:13
	// call automation related init method
		pCMyMath->InitInstance(); 

	// get the requested interface
	hr = pCMyMath->QueryInterface(riid, ppv); 

	pCMyMath->Release(); // anticipate possible failure of QueryInterface() 
	return(hr);
}

HRESULT CMyMathClassFactory::LockServer(BOOL fLock) 
{
	if (fLock)
		InterlockedIncrement(&glNumberOfServerLocks);
	else
		InterlockedDecrement(&glNumberOfServerLocks);

	return(S_OK);

}

//Implementation Of Exported functions from this Dll
extern "C"  HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	//variable declarations
	CMyMathClassFactory* pCMyMathClassFactory = NULL; 
	HRESULT hr = S_OK;

	//code
	if (rclsid != CLSID_MyMath)
		return(CLASS_E_CLASSNOTAVAILABLE);
	
	//create  class factory
	pCMyMathClassFactory = new CMyMathClassFactory; //constructor call 

	if (pCMyMathClassFactory == NULL) 
		return(E_OUTOFMEMORY);
	 
	hr = pCMyMathClassFactory->QueryInterface(riid, ppv); 
	pCMyMathClassFactory->Release();//anticipate possible failure of QueryInterface() 

	return(hr);

}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);//

}

//change no:14 implementation of the ComErrorDescriptionString method.

void ComErrorDescriptionString(HWND hwnd, HRESULT hr)
{
	//variable declarations 
	TCHAR* szErrorMessage = NULL;
	TCHAR str[255];

	if (FACILITY_WINDOWS == HRESULT_FACILITY(hr))
	{
		hr = HRESULT_CODE(hr);
		
		if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&szErrorMessage, 0, NULL) != 0)
		{
			swprintf_s(str, TEXT("%#x : %s"), hr, szErrorMessage);
			LocalFree(szErrorMessage);
		}
		else {
			swprintf_s(str, TEXT("[Could not find a description for error # %#x.]\n"),hr);
		}

		MessageBox(hwnd, str, TEXT("COM Error"), MB_OK);  
	}
}

