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

//CLSID OF Csumsubtract // {04D0356E-C087-495C-A5B0-3008FF6EB09A}
 const CLSID CLSID_SumSubtract = { 0x4d0356e, 0xc087, 0x495c, 0xa5, 0xb0, 0x30, 0x8, 0xff, 0x6e, 0xb0, 0x9a };


// IID of ISum Interface // {96F7CCCB-0A88-4A90-A044-98B541B8A840}
 const IID IID_ISum = { 0x96f7cccb, 0xa88, 0x4a90, 0xa0, 0x44, 0x98, 0xb5, 0x41, 0xb8, 0xa8, 0x40 };



// IID of ISubtract Interface // {54AB66C7-5813-45BC-823E-1FB893549510}
 const IID IID_ISubtract = { 0x54ab66c7, 0x5813, 0x45bc, 0x82, 0x3e, 0x1f, 0xb8, 0x93, 0x54, 0x95, 0x10 };




