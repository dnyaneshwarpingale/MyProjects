//With respect classfactorydllserver.cpp with outerdllserver.cpp there are 8 changes these 8 changes are appropriate places
#define UNICODE
#include<windows.h>
#include"ContainmentOuterDLLServer.h"
#include"ContainmentInnerDLLServer.h" //change number 1


//class declarations
//change number  2
//2a now outer coclass must aslo inherit fromm inner interface in addtion to its interfaces to show its client
//2b now in private data member declare interface pointers of inner dll servers
//2c now declare Imultiplication functionlities multiplicaitionoftwointegers() and IDevision functionalite devision(). also declare a new user defined member function initializeinnercomponent().
class CSumSubtract : public ISum, ISubtract,IMultiplication,IDevision  //Csumsubtract is kamgar adda or worker class
{
private:
	long m_cRef;
	IMultiplication* m_pIMultiplication;
	IDevision* m_pIDevision;

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

	//IMultiplication specific method declarations (inherited)
	HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);

	//IDevision specific method declarations (inherited)
	HRESULT __stdcall DevisionOfTwoIntegers(int, int, int*);

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

	InterlockedIncrement(&glNumberOfActiveComponents);//increment global counter

	//Change no 3 :Initialize the private data members interface pointers
	m_pIMultiplication = NULL;
	m_pIDevision = NULL;

	
}

//Implementation of CSumSubtract's Destructor Method 
CSumSubtract::~CSumSubtract(void)
{
	//changeNumber 4: saferelease coclass private memberdata interfaces
	if (m_pIDevision)
	{   
		m_pIDevision->Release();
		m_pIDevision = NULL;
	}

	if (m_pIMultiplication)
	{
		m_pIMultiplication->Release();

		m_pIMultiplication = NULL;
	}

	InterlockedDecrement(&glNumberOfActiveComponents);//decrement global counter
	
	

}

//Implementation of CSumSubtract's IUnknown's Methods
HRESULT CSumSubtract::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
		*ppv = static_cast<ISum*>(this);
	else if (riid == IID_ISum)
		*ppv = static_cast<ISum*>(this);
	else if (riid == IID_ISubtract)
		*ppv = static_cast<ISubtract*>(this);
	//Change number 5: According to inheritance list of coclass now provide implementations of inners interface if queried by client.
	else if (riid == IID_IMultiplication)
		*ppv = static_cast<IMultiplication*>(this);
	else if (riid == IID_IDevision)
		*ppv = static_cast<IDevision*>(this);
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

//Change number 6:Implementation of Inner functionalities.
//6a now outercoclass must defines its multiplicationoftwointeger() but must call inners multiplicationoftwointegers()
//6a now outercoclass must defines its multiplicationoftwointeger() but must call inners multiplicationoftwointegers()

HRESULT CSumSubtract::MultiplicationOfTwoIntegers(int num1, int num2, int* pMultiplication)
{
	m_pIMultiplication->MultiplicationOfTwoIntegers(num1, num2, pMultiplication); 
	return(S_OK);
}

HRESULT CSumSubtract::DevisionOfTwoIntegers(int num1, int num2, int* pDevison)
{
	m_pIDevision->DevisionOfTwoIntegers(num1, num2, pDevison); 
	return(S_OK);
}

//Change number 7: define initializeinnercomponent() which will call cocreateinstance which will call containment inner dll
HRESULT CSumSubtract::InitializeInnerComponent(void)
{
	//code
	HRESULT hr = S_OK;
	hr = CoCreateInstance(CLSID_MultiplicationDevision, NULL, CLSCTX_INPROC_SERVER, IID_IMultiplication, (void**)&m_pIMultiplication);

	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("IMultiplication Interface Can Not Be Obtained From Inner Component."), TEXT("Error"), MB_OK);
		return(E_FAIL);
	}

	hr = m_pIMultiplication->QueryInterface(IID_IDevision, (void**)&m_pIDevision);

	if (FAILED(hr)) 
	{   
		MessageBox(NULL, TEXT("IDevision Interface Can Not Be Obtained From Inner Component."), TEXT("Error"), MB_OK);
		m_pIMultiplication->Release(); 
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

