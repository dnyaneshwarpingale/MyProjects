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

//CLSID OF CMultiplicationDevision // {EC0B31AF-97D8-4D77-95EA-CE542F1FBE6D}
 const CLSID CLSID_MultiplicationDevision = { 0xec0b31af, 0x97d8, 0x4d77, 0x95, 0xea, 0xce, 0x54, 0x2f, 0x1f, 0xbe, 0x6d };


// IID of IMultiplication Interface // {469964DE-28BF-4DFD-9CEB-D69560398F97}
 const IID IID_IMultiplication = { 0x469964de, 0x28bf, 0x4dfd, 0x9c, 0xeb, 0xd6, 0x95, 0x60, 0x39, 0x8f, 0x97 };


// IID of IDevision Interface // {0C889946-D477-465D-88C9-C49FEC25784A}
 const IID IID_IDevision = { 0xc889946, 0xd477, 0x465d, 0x88, 0xc9, 0xc4, 0x9f, 0xec, 0x25, 0x78, 0x4a };







