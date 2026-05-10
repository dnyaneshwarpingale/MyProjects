//changes in aggreagation outer dll server with respect to the containment dll server there are 6 changes and marked at appropriate location.

#include<windows.h>
#include"DesaturationSepiaNegativeDLL.h"
#include"NegativeDLL.h" 


//class declarations
//change no:1
//Unlike containment outer coclass aggregation outer coclass inherit and implement only its own interface isum and isubtract . it will not implement imultiplication and idevision.
class CDesaturationSepia : public IDesaturation, ISepia  //Csumsubtract is kamgar adda or worker class
{
private:
	long m_cRef;

	//changeno:2 to store the iknown of aggregation inner component.
	IUnknown* m_pIUnknownInner;

public:
	//constructor method declarationse
	CDesaturationSepia(void);

	//destructor method declarations
	~CDesaturationSepia(void);

	//IUnknown specific method declarations (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//Isum specific method declarations (inherited)
	HRESULT __stdcall ApplyDesaturation(COLORREF originalpixelColor, COLORREF* dsaturatedColor);

	//ISubtract specific method declarations (inherited)
	HRESULT __stdcall ApplySepia(COLORREF originalpixelColor, COLORREF* sepiaColor); 

	//Coclasses own userdefined Function
	HRESULT __stdcall InitializeInnerComponent(void);

};

class CDesaturationSepiaClassFactory :public IClassFactory 
{
private:
	long m_cRef;

public:
	//constructor method declarations
	CDesaturationSepiaClassFactory(void);

	//destructor method declarations
	~CDesaturationSepiaClassFactory(void);

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
CDesaturationSepia::CDesaturationSepia(void)
{
	//hardcoded initialization to anticipate possible possible failure of QueryInterface()
	m_cRef = 1;
	m_pIUnknownInner = NULL;  //change no:3

	InterlockedIncrement(&glNumberOfActiveComponents);//increment global counter

	
}

//Implementation of CSumSubtract's Destructor Method 
CDesaturationSepia::~CDesaturationSepia(void)
{

	InterlockedDecrement(&glNumberOfActiveComponents);//decrement global counter

	if (m_pIUnknownInner) //change no:4
	{
		m_pIUnknownInner->Release();
		m_pIUnknownInner = NULL;
	}

	

}

//Implementation of CSumSubtract's IUnknown's Methods
HRESULT CDesaturationSepia::QueryInterface(REFIID riid, void** ppv)
{
	//code

	if (riid == IID_IUnknown)
		*ppv = static_cast<IDesaturation*>(this); 
	else if (riid == IID_IDesaturation)
		*ppv = static_cast<IDesaturation*>(this); 
	else if (riid == IID_ISepia) 
		*ppv = static_cast<ISepia*>(this); 
	//Change number 5:
	else if (riid == IID_INegative)
		return(m_pIUnknownInner->QueryInterface(riid, ppv));
	else
	{
		*ppv = NULL;
		return (E_NOINTERFACE);
	}

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();

	return(S_OK);

}

ULONG CDesaturationSepia::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CDesaturationSepia::Release(void)
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
HRESULT CDesaturationSepia::ApplyDesaturation(COLORREF originalpixelColor, COLORREF* dsaturatedColor) 
{
	unsigned int originalR = GetRValue(originalpixelColor);//we have not used hdc from this point  
	unsigned int originalG = GetGValue(originalpixelColor); 
	unsigned int originalB = GetBValue(originalpixelColor); 

	// calculating dsaturated value
	unsigned int dSaturatedR = (unsigned int)(float)originalR * 0.3f; 
	unsigned int dSaturatedG = (unsigned int)(float)originalG * 0.59f; 
	unsigned int dSaturatedB = (unsigned int)(float)originalB * 0.11f; 

	// Add up dR and dG and dB color component to get final dsaturated color for the pixel
	unsigned int finalDsaturatedColor = dSaturatedR + dSaturatedG + dSaturatedB; 

	// set final dsaturated color back to the same pixel or at coordinate xColumn, yRow
	 *dsaturatedColor = RGB(finalDsaturatedColor, finalDsaturatedColor, finalDsaturatedColor);

	return(S_OK);
}

//Implementation of ISubtract's Methods
HRESULT CDesaturationSepia::ApplySepia(COLORREF originalpixelColor, COLORREF* sepiaColor) 
{
	unsigned int originalR = GetRValue(originalpixelColor);
	unsigned int originalG = GetGValue(originalpixelColor);
	unsigned int originalB = GetBValue(originalpixelColor);

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
	*sepiaColor = RGB(sephiyaR, sephiyaG, sephiyaB);
	return(S_OK);
}


//Change number 7: define initializeinnercomponent() which will call cocreateinstance which will call containment inner dll
HRESULT CDesaturationSepia::InitializeInnerComponent(void)
{
	//code
	HRESULT hr = S_OK;
	//change no:6-this is the point of aggregation
	hr = CoCreateInstance(CLSID_Negative, reinterpret_cast<IUnknown*>(this), CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&m_pIUnknownInner); 

	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("Falied to Obtained IUnknown of Inner Component."), TEXT("Error"), MB_OK);
		return(E_FAIL);
	}


	return(hr);
}


//Implementation of CSumSubtractClassFactory's Constructor Method
CDesaturationSepiaClassFactory::CDesaturationSepiaClassFactory(void)
{
	m_cRef = 1; //hardcoded initialization to antcipate possible failure of QueryInterface()
}

//Implementation of CSumSubtractClassFactory's Destructor method
CDesaturationSepiaClassFactory::~CDesaturationSepiaClassFactory(void)
{
	//no code
}

//Implementation of CSumSubtractCassFactory's IClassFactory's IUnknown's Methods
HRESULT CDesaturationSepiaClassFactory::QueryInterface(REFIID riid, void** ppv)
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

ULONG CDesaturationSepiaClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);

}

ULONG CDesaturationSepiaClassFactory::Release(void)
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
HRESULT CDesaturationSepiaClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	//variable declarations
	CDesaturationSepia* pCDesaturationSepia = NULL;
	HRESULT hr = S_OK;

	//code
	if (pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);

	// create the instance of component i.e. of CSumSubtract class
	pCDesaturationSepia = new CDesaturationSepia;  //call to constructor to get memory.


	if (pCDesaturationSepia == NULL)
		return(E_OUTOFMEMORY);     

	//change no:* call //initialize the inner component to load the Inner DLL
	hr= pCDesaturationSepia->InitializeInnerComponent(); 

	if (FAILED(hr))
	{

		MessageBox(NULL, TEXT("Failed To Initialize Inner Component"), TEXT("Error"), MB_OK); 
		pCDesaturationSepia->Release(); 
		return(hr); 
	}

	// get the requested interface
	hr = pCDesaturationSepia->QueryInterface(riid, ppv); 

	pCDesaturationSepia->Release(); // anticipate possible failure of QueryInterface() 
	return(hr); 
}

HRESULT CDesaturationSepiaClassFactory::LockServer(BOOL fLock)
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
	CDesaturationSepiaClassFactory* pCDesaturationSepiaClassFactory = NULL; 
	HRESULT hr = S_OK;

	//code
	if (rclsid != CLSID_DesaturationSepia)
		return(CLASS_E_CLASSNOTAVAILABLE);
	
	//create  class factory
	pCDesaturationSepiaClassFactory = new CDesaturationSepiaClassFactory; //constructor call

	if (pCDesaturationSepiaClassFactory == NULL)
		return(E_OUTOFMEMORY);

	hr = pCDesaturationSepiaClassFactory->QueryInterface(riid, ppv); 
	pCDesaturationSepiaClassFactory->Release();//anticipate possible failure of QueryInterface() 

	return(hr);

}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return(S_OK);
	else
		return(S_FALSE);//

}


