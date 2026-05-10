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


 class IMultiplication :public IUnknown //IMultipliction mnje IRajeshPradhan
 {
 public:
	 //inherited fn 1)QueryInterface() 2) AddRef() 3) Release() from IUnknown

	//isumm
	 virtual HRESULT _stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0;
 };

 class IDevision :public IUnknown //IDevision  mnje IRajeshPradhan
 {
 public:
	 //inherited fn 1)QueryInterface 2) AddRef 3) Release from IUnknown

	 //isub
	 virtual HRESULT _stdcall DevisionOfTwoIntegers(int, int, int*) = 0;
 };

//CLSID OF Csumsubtract // {04D0356E-C087-495C-A5B0-3008FF6EB09A}
 const CLSID CLSID_SumSubtract = { 0x4d0356e, 0xc087, 0x495c, 0xa5, 0xb0, 0x30, 0x8, 0xff, 0x6e, 0xb0, 0x9a };


// IID of ISum Interface // {96F7CCCB-0A88-4A90-A044-98B541B8A840}
 const IID IID_ISum = { 0x96f7cccb, 0xa88, 0x4a90, 0xa0, 0x44, 0x98, 0xb5, 0x41, 0xb8, 0xa8, 0x40 };



// IID of ISubtract Interface // {54AB66C7-5813-45BC-823E-1FB893549510}
 const IID IID_ISubtract = { 0x54ab66c7, 0x5813, 0x45bc, 0x82, 0x3e, 0x1f, 0xb8, 0x93, 0x54, 0x95, 0x10 };

 // IID of IMultiplication Interface // {43B59DE4-6FCE-446A-A6EA-78C4CC053DF8}
 const IID IID_IMultiplication = { 0x43b59de4, 0x6fce, 0x446a, 0xa6, 0xea, 0x78, 0xc4, 0xcc, 0x5, 0x3d, 0xf8 };

 // IID of IDevision Interface // {ED1F0C36-7C97-44A2-AC1D-E915D1A333CE}
 const IID IID_IDevision = { 0xed1f0c36, 0x7c97, 0x44a2, 0xac, 0x1d, 0xe9, 0x15, 0xd1, 0xa3, 0x33, 0xce };






