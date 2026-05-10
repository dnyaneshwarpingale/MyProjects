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

//CLSID OF Csumsubtract // {585F3BC5-1052-4E02-AC13-0645945F484B}
 const CLSID CLSID_SumSubtract = { 0x585f3bc5, 0x1052, 0x4e02, 0xac, 0x13, 0x6, 0x45, 0x94, 0x5f, 0x48, 0x4b };


// IID of ISum Interface // {7280CDB7-64F5-424E-9FBD-C0129C8867E4}
 const IID IID_ISum = { 0x7280cdb7, 0x64f5, 0x424e, 0x9f, 0xbd, 0xc0, 0x12, 0x9c, 0x88, 0x67, 0xe4 };


// IID of ISubtract Interface // {FB95BACA-4686-4433-AD81-536C8B80956E}
 const IID IID_ISubtract = { 0xfb95baca, 0x4686, 0x4433, 0xad, 0x81, 0x53, 0x6c, 0x8b, 0x80, 0x95, 0x6e };


 // IID of IMultiplication Interface // {469964DE-28BF-4DFD-9CEB-D69560398F97}
 const IID IID_IMultiplication = { 0x469964de, 0x28bf, 0x4dfd, 0x9c, 0xeb, 0xd6, 0x95, 0x60, 0x39, 0x8f, 0x97 };


 // IID of IDevision Interface // {0C889946-D477-465D-88C9-C49FEC25784A}
 const IID IID_IDevision = { 0xc889946, 0xd477, 0x465d, 0x88, 0xc9, 0xc4, 0x9f, 0xec, 0x25, 0x78, 0x4a };







