#pragma once

 class ISum :public IUnknown //ISum mnje IRajeshPradhan
{
public:
	//inherited fn 1)QueryInterface() 2) AddRef() 3) Release() from IUnknown
	
   //isumm
	virtual HRESULT _stdcall SumOfTwoIntegers(int, int, int*) = 0;
};

 class ISubtract :public IUnknown //ISubstract  mnje IRajeshPradhan
{
public:
	//inherited fn 1)QueryInterface 2) AddRef 3) Release from IUnknown

	//isub
	virtual HRESULT _stdcall SubtractionOfTwoIntegers(int, int, int*) = 0;
};

//CLSID OF Csumsubtract // {474044A5-AEC4-4067-BF78-4793D358FB53} used in registry string guid
const CLSID CLSID_SumSubtract = { 0x474044a5, 0xaec4, 0x4067, 0xbf, 0x78, 0x47, 0x93, 0xd3, 0x58, 0xfb, 0x53 }; //used in code numeric guid

// IID of ISum Interface // {1041B596-053E-4FDC-B2EF-E5860F7DBF53}
const IID IID_ISum = { 0x1041b596, 0x53e, 0x4fdc, 0xb2, 0xef, 0xe5, 0x86, 0xf, 0x7d, 0xbf, 0x53 };


// IID of ISubtract Interface // {64D285E6-A187-43F1-B169-B7D3BA8F2534}
const IID IID_ISubtract = { 0x64d285e6, 0xa187, 0x43f1, 0xb1, 0x69, 0xb7, 0xd3, 0xba, 0x8f, 0x25, 0x34 };


