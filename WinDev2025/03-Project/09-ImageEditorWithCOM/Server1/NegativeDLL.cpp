/*changes in AggregationInnerDLLServer.cpp with respect containmentInnerDLLServer.cpp are:
There are total 12 changes which  are marked at appropriate location throughout the code.
*/

#include<windows.h>
#include"NegativeDLL.h"

//change no:1 interface declaration (for internal use only. i.e not be included in .h file 

interface INoAggregationIUnknown
{
	virtual HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**) = 0;
	virtual ULONG __stdcall AddRef_NoAggregation(void) = 0;
	virtual ULONG __stdcall Release_NoAggregation(void) = 0;
};

//change2: inner coclass first inherit from INoAggregationIUnknown 
//class declarations
class CNegative : public INoAggregationIUnknown, INegative //Csumsubtract is kamgar adda or worker class
{
private:
	long m_cRef;
	//m stands for member data change3: in Aggregation inners coclass declare iunkwon pointer to store iunknown aggregation outer
	IUnknown* m_pIUnknownOuter;
public:
	//chNGE 4A: FOR THE FIRST TIME CONSTRUCTOR AGGREGATION COCLASS IS GOING TO BE PARAMETERIZED AND IT IS GOING TO TAKE IWNKNOWN POIONTER AS ITS PARAMETER
	//constructor method declarations
	CNegative(IUnknown *);

	//destructor method declarations
	~CNegative(void);

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
	HRESULT __stdcall ApplyNegative(COLORREF originalpixelColor, COLORREF* negativeColor); 


};

class CNegativeClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:
	//constructor method declarations
	CNegativeClassFactory(void);

	//destructor method declarations
	~CNegativeClassFactory(void);

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
CNegative::CNegative(IUnknown *pIUnknownOuter)
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
CNegative::~CNegative(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);//decrement global counter

}

//change no :6
//Implementation of CMultiplicationDevision's IUnknown's Methods
HRESULT CNegative::QueryInterface_NoAggregation(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
		*ppv = static_cast<INoAggregationIUnknown*>(this);  
	else if (riid == IID_INegative)
		*ppv = static_cast<INegative*>(this); 
	else
	{
		*ppv = NULL;
		return (E_NOINTERFACE);
	}

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();

	return(S_OK);

}
//change no:7
ULONG CNegative::AddRef_NoAggregation(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}
//change no 8
ULONG CNegative::Release_NoAggregation(void)
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return(0);

	}

	return(m_cRef);

}

HRESULT CNegative::QueryInterface(REFIID riid, void** ppv)
{
	//change no :9
	return(m_pIUnknownOuter->QueryInterface(riid, ppv)); 

}

ULONG CNegative::AddRef(void)
{
	//change no:10
	return(m_pIUnknownOuter->AddRef()); 

}

ULONG CNegative::Release(void)
{
	//change no:11

	return(m_pIUnknownOuter->Release()); 

}

//Implementation Of ISum's Methods
HRESULT CNegative::ApplyNegative(COLORREF originalpixelColor, COLORREF* negativeColor) 
{
	unsigned int originalR = GetRValue(originalpixelColor);
	unsigned int originalG = GetGValue(originalpixelColor);
	unsigned int originalB = GetBValue(originalpixelColor);

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
	 *negativeColor = RGB(negativeR, negativeG, negativeB);

	return(S_OK);
}



//Implementation of CSumSubtractClassFactory's Constructor Method
CNegativeClassFactory::CNegativeClassFactory(void)
{
	m_cRef = 1; //hardcoded initialization to antcipate possible failure of QueryInterface()
}

//Implementation of CSumSubtractClassFactory's Destructor method
CNegativeClassFactory::~CNegativeClassFactory(void)
{
	//no code
}

//Implementation of CSumSubtractCassFactory's IClassFactory's IUnknown's Methods
HRESULT CNegativeClassFactory::QueryInterface(REFIID riid, void** ppv)
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

ULONG CNegativeClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CNegativeClassFactory::Release(void)
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
HRESULT CNegativeClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//variable declarations
	CNegative* pCNegative = NULL;
	HRESULT hr = S_OK;

	//code
	//change NO:12A- if your punkouter is not null which means its your valid pointer then for aggregation second parameter must be riid is IID_IUnknown
	if ((pUnkOuter != NULL) && (riid != IID_IUnknown))  
		return(CLASS_E_NOAGGREGATION);
	 
	//change12B:pass the parameter to the constructor.
	// create the instance of component i.e. of CSumSubtract class
	pCNegative = new CNegative(pUnkOuter);  //call to constructor to get memory. 

	if (pCNegative == NULL)
		return(E_OUTOFMEMORY);       
	
	//change12C
	// get the requested interface
	hr = pCNegative->QueryInterface_NoAggregation(riid, ppv); 

	pCNegative->Release_NoAggregation(); // anticipate possible failure of QueryInterface()  
	return(hr);
}

HRESULT CNegativeClassFactory::LockServer(BOOL fLock)
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
	CNegativeClassFactory* pCNegativeClassFactory = NULL;
	HRESULT hr = S_OK;

	//code
	if (rclsid != CLSID_Negative)
		return(CLASS_E_CLASSNOTAVAILABLE);
	
	//create  class factory
	pCNegativeClassFactory = new CNegativeClassFactory; //constructor call 

	if (pCNegativeClassFactory == NULL)
		return(E_OUTOFMEMORY);

	hr = pCNegativeClassFactory->QueryInterface(riid, ppv); 
	pCNegativeClassFactory->Release();//anticipate possible failure of QueryInterface()  

	return(hr);

}


extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);//

}


