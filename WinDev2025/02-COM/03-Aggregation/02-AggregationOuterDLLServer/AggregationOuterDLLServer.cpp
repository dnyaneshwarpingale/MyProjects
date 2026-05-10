//changes in aggreagation outer dll server with respect to the containment dll server there are 6 changes and marked at appropriate location.

#include<windows.h>
#include"AggregationOuterDLLServer.h"
#include"AggregationInnerDLLServer.h" 


//class declarations
//change no:1
//Unlike containment outer coclass aggregation outer coclass inherit and implement only its own interface isum and isubtract . it will not implement imultiplication and idevision.
class CSumSubtract : public ISum, ISubtract  //Csumsubtract is kamgar adda or worker class
{
private:
	long m_cRef;

	//changeno:2 to store the iknown of aggregation inner component.
	IUnknown* m_pIUnknownInner;

public:
	//constructor method declarationse
	CSumSubtract(void);

	//destructor method declarations
	~CSumSubtract(void);

	//IUnknown specific method declarations (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//Isum specific method declarations (inherited)
	HRESULT __stdcall SumOfTwoIntegers(int, int, int*);

	//ISubtract specific method declarations (inherited)
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);

	//Coclasses own userdefined Function
	HRESULT __stdcall InitializeInnerComponent(void);

};

class CSumSubtractClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:
	//constructor method declarations
	CSumSubtractClassFactory(void);

	//destructor method declarations
	~CSumSubtractClassFactory(void);

	//IUnknown specific method declarations (inherted)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory specific method declarations (inherited)
	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);


};

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
CSumSubtract::CSumSubtract(void)
{
	//hardcoded initialization to anticipate possible possible failure of QueryInterface()
	m_cRef = 1;
	m_pIUnknownInner = NULL;  //change no:3

	InterlockedIncrement(&glNumberOfActiveComponents);//increment global counter

	
}

//Implementation of CSumSubtract's Destructor Method 
CSumSubtract::~CSumSubtract(void)
{

	InterlockedDecrement(&glNumberOfActiveComponents);//decrement global counter

	if (m_pIUnknownInner) //change no:4
	{
		m_pIUnknownInner->Release();
		m_pIUnknownInner = NULL;
	}

	

}

//Implementation of CSumSubtract's IUnknown's Methods
HRESULT CSumSubtract::QueryInterface(REFIID riid, void** ppv)
{
	//code

	if (riid == IID_IUnknown)
		*ppv = static_cast<ISum*>(this);
	else if (riid == IID_ISum)
		*ppv = static_cast<ISum*>(this);
	else if (riid == IID_ISubtract)
		*ppv = static_cast<ISubtract*>(this);
	//Change number 5:
	else if (riid == IID_IMultiplication)
		return(m_pIUnknownInner->QueryInterface(riid, ppv));
	else if (riid == IID_IDevision)
		return(m_pIUnknownInner->QueryInterface(riid, ppv)); 
	else
	{
		*ppv = NULL;
		return (E_NOINTERFACE);
	}

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();

	return(S_OK);

}

ULONG CSumSubtract::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CSumSubtract::Release(void)
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return(0);

	}

	return(m_cRef);

}

//Implementation Of ISum's Methods
HRESULT CSumSubtract::SumOfTwoIntegers(int num1, int num2, int* pSum)
{
	*pSum = num1 + num2;

	return(S_OK);
}

//Implementation of ISubtract's Methods
HRESULT CSumSubtract::SubtractionOfTwoIntegers(int num1, int num2, int* pSubtract)
{
	*pSubtract = num1 - num2;
	return(S_OK);
}


//Change number 7: define initializeinnercomponent() which will call cocreateinstance which will call containment inner dll
HRESULT CSumSubtract::InitializeInnerComponent(void)
{
	//code
	HRESULT hr = S_OK;
	//change no:6-this is the point of aggregation
	hr = CoCreateInstance(CLSID_MultiplicationDevision, reinterpret_cast<IUnknown*>(this), CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&m_pIUnknownInner);

	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("Falied to Obtained IUnknown of Inner Component."), TEXT("Error"), MB_OK);
		return(E_FAIL);
	}


	return(hr);
}


//Implementation of CSumSubtractClassFactory's Constructor Method
CSumSubtractClassFactory::CSumSubtractClassFactory(void)
{
	m_cRef = 1; //hardcoded initialization to antcipate possible failure of QueryInterface()
}

//Implementation of CSumSubtractClassFactory's Destructor method
CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
	//no code
}

//Implementation of CSumSubtractCassFactory's IClassFactory's IUnknown's Methods
HRESULT CSumSubtractClassFactory::QueryInterface(REFIID riid, void** ppv)
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

ULONG CSumSubtractClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CSumSubtractClassFactory::Release(void)
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
HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//variable declarations
	CSumSubtract* pCSumSubtract = NULL;
	HRESULT hr = S_OK;

	//code
	if (pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);

	// create the instance of component i.e. of CSumSubtract class
	pCSumSubtract = new CSumSubtract;  //call to constructor to get memory.


	if (pCSumSubtract == NULL)
		return(E_OUTOFMEMORY);     

	//change no:* call //initialize the inner component to load the Inner DLL
	hr=pCSumSubtract->InitializeInnerComponent(); 

	if (FAILED(hr))
	{

		MessageBox(NULL, TEXT("Failed To Initialize Inner Component"), TEXT("Error"), MB_OK); 
		pCSumSubtract->Release(); 
		return(hr); 
	}

	// get the requested interface
	hr = pCSumSubtract->QueryInterface(riid, ppv);

	pCSumSubtract->Release(); // anticipate possible failure of QueryInterface()
	return(hr);
}

HRESULT CSumSubtractClassFactory::LockServer(BOOL fLock)
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
	CSumSubtractClassFactory* pCSumSubtractClassFactory = NULL;
	HRESULT hr = S_OK;

	//code
	if (rclsid != CLSID_SumSubtract)
		return(CLASS_E_CLASSNOTAVAILABLE);
	
	//create  class factory
	pCSumSubtractClassFactory = new CSumSubtractClassFactory; //constructor call

	if (pCSumSubtractClassFactory == NULL)
		return(E_OUTOFMEMORY);

	hr = pCSumSubtractClassFactory->QueryInterface(riid, ppv);
	pCSumSubtractClassFactory->Release();//anticipate possible failure of QueryInterface()

	return(hr);

}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);//

}

