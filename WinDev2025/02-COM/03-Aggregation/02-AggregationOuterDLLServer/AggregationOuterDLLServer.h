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

//CLSID OF Csumsubtract // {585F3BC5-1052-4E02-AC13-0645945F484B}
 const CLSID CLSID_SumSubtract = { 0x585f3bc5, 0x1052, 0x4e02, 0xac, 0x13, 0x6, 0x45, 0x94, 0x5f, 0x48, 0x4b };


// IID of ISum Interface // {7280CDB7-64F5-424E-9FBD-C0129C8867E4}
 const IID IID_ISum = { 0x7280cdb7, 0x64f5, 0x424e, 0x9f, 0xbd, 0xc0, 0x12, 0x9c, 0x88, 0x67, 0xe4 };


// IID of ISubtract Interface // {FB95BACA-4686-4433-AD81-536C8B80956E}
 const IID IID_ISubtract = { 0xfb95baca, 0x4686, 0x4433, 0xad, 0x81, 0x53, 0x6c, 0x8b, 0x80, 0x95, 0x6e };






