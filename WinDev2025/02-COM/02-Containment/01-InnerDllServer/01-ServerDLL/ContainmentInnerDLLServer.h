#pragma once

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

//CLSID OF CMultiplicationDevision // {4A414747-6A29-4BB9-9C12-87DE49B25432}
 const CLSID CLSID_MultiplicationDevision = { 0x4a414747, 0x6a29, 0x4bb9, 0x9c, 0x12, 0x87, 0xde, 0x49, 0xb2, 0x54, 0x32 };

// IID of IMultiplication Interface // {43B59DE4-6FCE-446A-A6EA-78C4CC053DF8}
 const IID IID_IMultiplication = { 0x43b59de4, 0x6fce, 0x446a, 0xa6, 0xea, 0x78, 0xc4, 0xcc, 0x5, 0x3d, 0xf8 };

// IID of IDevision Interface // {ED1F0C36-7C97-44A2-AC1D-E915D1A333CE}
 const IID IID_IDevision = { 0xed1f0c36, 0x7c97, 0x44a2, 0xac, 0x1d, 0xe9, 0x15, 0xd1, 0xa3, 0x33, 0xce };





