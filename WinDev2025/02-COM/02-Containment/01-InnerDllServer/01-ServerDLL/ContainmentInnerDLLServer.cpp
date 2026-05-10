/*changes in containmentinnerdllserver.cpp with respect classfactory.cpp are:
1) Coclass is implementing interfaces imultiplication and idevision
2) coclass name is cmultiplicatioDevision 
3) classFactory name is cmultiplicationdevisionclassfactory
4)implementing two functionalities are muloftwo() and devisionoftwono()
 
*/
#define UNICODE
#include<windows.h>
#include"ContainmentInnerDLLServer.h"

//class declarations
class CMultiplicationDevision : public IMultiplication, IDevision  //Csumsubtract is kamgar adda or worker class
{
private:
	long m_cRef;

public:
	//constructor method declarations
	CMultiplicationDevision(void);

	//destructor method declarations
	~CMultiplicationDevision(void);

	//IUnknown specific method declarations (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//Isum specific method declarations (inherited)
	HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);

	//ISubtract specific method declarations (inherited)
	HRESULT __stdcall DevisionOfTwoIntegers(int, int, int*);

};

class CMultiplicationDevisionClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:
	//constructor method declarations
	CMultiplicationDevisionClassFactory(void);

	//destructor method declarations
	~CMultiplicationDevisionClassFactory(void);

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
CMultiplicationDevision::CMultiplicationDevision(void)
{
	//hardcoded initialization to anticipate possible possible failure of QueryInterface()
	m_cRef = 1;

	InterlockedIncrement(&glNumberOfActiveComponents);//increment global counter
}

//Implementation of CSumSubtract's Destructor Method 
CMultiplicationDevision::~CMultiplicationDevision(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);//decrement global counter

}

//Implementation of CSumSubtract's IUnknown's Methods
HRESULT CMultiplicationDevision::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
		*ppv = static_cast<IMultiplication*>(this); 
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

ULONG CMultiplicationDevision::AddRef(void) 
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CMultiplicationDevision::Release(void)
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
HRESULT CMultiplicationDevision::MultiplicationOfTwoIntegers(int num1, int num2, int* pMultiplication)
{
	*pMultiplication = num1 * num2;  

	return(S_OK);
}

//Implementation of ISubtract's Methods
HRESULT CMultiplicationDevision::DevisionOfTwoIntegers(int num1, int num2, int* pDevision)
{
	*pDevision = num1 / num2; 
	return(S_OK);
}

//Implementation of CSumSubtractClassFactory's Constructor Method
CMultiplicationDevisionClassFactory::CMultiplicationDevisionClassFactory(void)
{
	m_cRef = 1; //hardcoded initialization to antcipate possible failure of QueryInterface()
}

//Implementation of CSumSubtractClassFactory's Destructor method
CMultiplicationDevisionClassFactory::~CMultiplicationDevisionClassFactory(void)
{
	//no code
}

//Implementation of CSumSubtractCassFactory's IClassFactory's IUnknown's Methods
HRESULT CMultiplicationDevisionClassFactory::QueryInterface(REFIID riid, void** ppv)
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

ULONG CMultiplicationDevisionClassFactory::AddRef(void) 
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CMultiplicationDevisionClassFactory::Release(void) 
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
HRESULT CMultiplicationDevisionClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv) 
{
	//variable declarations
	CMultiplicationDevision* pCMultiplicationDevision = NULL; 
	HRESULT hr = S_OK;

	//code
	if (pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);

	// create the instance of component i.e. of CSumSubtract class
	pCMultiplicationDevision = new CMultiplicationDevision;  //call to constructor to get memory. 

	if (pCMultiplicationDevision == NULL) 
		return(E_OUTOFMEMORY);      

	// get the requested interface
	hr = pCMultiplicationDevision->QueryInterface(riid, ppv); 

	pCMultiplicationDevision->Release(); // anticipate possible failure of QueryInterface() 
	return(hr);
}

HRESULT CMultiplicationDevisionClassFactory::LockServer(BOOL fLock) 
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
	CMultiplicationDevisionClassFactory* pCMultiplicationDevisionClassFactory = NULL; 
	HRESULT hr = S_OK;

	//code
	if (rclsid != CLSID_MultiplicationDevision)
		return(CLASS_E_CLASSNOTAVAILABLE);
	
	//create  class factory
	pCMultiplicationDevisionClassFactory = new CMultiplicationDevisionClassFactory; //constructor call 

	if (pCMultiplicationDevisionClassFactory == NULL) 
		return(E_OUTOFMEMORY);

	hr = pCMultiplicationDevisionClassFactory->QueryInterface(riid, ppv); 
	pCMultiplicationDevisionClassFactory->Release();//anticipate possible failure of QueryInterface() 

	return(hr);

}


extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);//

}


