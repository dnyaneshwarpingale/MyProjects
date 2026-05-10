/*changes in AggregationInnerDLLServer.cpp with respect containmentInnerDLLServer.cpp are:
There are total 12 changes which  are marked at appropriate location throughout the code.
*/

#include<windows.h>
#include"AggregationInnerDLLServer.h"

//change no:1 interface declaration (for internal use only. i.e not be included in .h file 

interface INoAggregationIUnknown
{
	virtual HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**) = 0;
	virtual ULONG __stdcall AddRef_NoAggregation(void) = 0;
	virtual ULONG __stdcall Release_NoAggregation(void) = 0;
};

//change2: inner coclass first inherit from INoAggregationIUnknown 
//class declarations
class CMultiplicationDevision : public INoAggregationIUnknown, IMultiplication, IDevision  //Csumsubtract is kamgar adda or worker class
{
private:
	long m_cRef;
	//m stands for member data change3: in Aggregation inners coclass declare iunkwon pointer to store iunknown aggregation outer
	IUnknown* m_pIUnknownOuter;
public:
	//chNGE 4A: FOR THE FIRST TIME CONSTRUCTOR AGGREGATION COCLASS IS GOING TO BE PARAMETERIZED AND IT IS GOING TO TAKE IWNKNOWN POIONTER AS ITS PARAMETER
	//constructor method declarations
	CMultiplicationDevision(IUnknown *);

	//destructor method declarations
	~CMultiplicationDevision(void);

	//change no 4b:
	//INOAGGREGATIONIUNKNOWN METHOD DECLARATIOS
	HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**);
	ULONG __stdcall AddRef_NoAggregation(void);
	ULONG __stdcall Release_NoAggregation(void);



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
CMultiplicationDevision::CMultiplicationDevision(IUnknown *pIUnknownOuter)
{
	//hardcoded initialization to anticipate possible possible failure of QueryInterface()
	m_cRef = 1;

	InterlockedIncrement(&glNumberOfActiveComponents);//increment global counter
	
	//change no5 assigning aggreagtionouter iunknown pointer to aggregation Iunknnown * m_pIUnknownouuter.

	if (pIUnknownOuter != NULL)
		m_pIUnknownOuter = pIUnknownOuter;
	else
		m_pIUnknownOuter = reinterpret_cast<IUnknown*>(static_cast<INoAggregationIUnknown*>(this));//***** 
}

//Implementation of CSumSubtract's Destructor Method 
CMultiplicationDevision::~CMultiplicationDevision(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);//decrement global counter

}

//change no :6
//Implementation of CMultiplicationDevision's IUnknown's Methods
HRESULT CMultiplicationDevision::QueryInterface_NoAggregation(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
		*ppv = static_cast<INoAggregationIUnknown*>(this);  
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
//change no:7
ULONG CMultiplicationDevision::AddRef_NoAggregation(void) 
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}
//change no 8
ULONG CMultiplicationDevision::Release_NoAggregation(void)
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return(0);

	}

	return(m_cRef);

}

HRESULT CMultiplicationDevision::QueryInterface(REFIID riid, void** ppv)
{
	//change no :9
	return(m_pIUnknownOuter->QueryInterface(riid, ppv)); 

}

ULONG CMultiplicationDevision::AddRef(void)
{
	//change no:10
	return(m_pIUnknownOuter->AddRef()); 

}

ULONG CMultiplicationDevision::Release(void)
{
	//change no:11

	return(m_pIUnknownOuter->Release()); 

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
	//change NO:12A- if your punkouter is not null which means its your valid pointer then for aggregation second parameter must be riid is IID_IUnknown
	if ((pUnkOuter != NULL) && (riid != IID_IUnknown))  
		return(CLASS_E_NOAGGREGATION);
	 
	//change12B:pass the parameter to the constructor.
	// create the instance of component i.e. of CSumSubtract class
	pCMultiplicationDevision = new CMultiplicationDevision(pUnkOuter);  //call to constructor to get memory. 

	if (pCMultiplicationDevision == NULL) 
		return(E_OUTOFMEMORY);       
	
	//change12C
	// get the requested interface
	hr = pCMultiplicationDevision->QueryInterface_NoAggregation(riid, ppv); 

	pCMultiplicationDevision->Release_NoAggregation(); // anticipate possible failure of QueryInterface() 
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


