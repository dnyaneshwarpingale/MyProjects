#pragma once

//undefined any any interface if present because we are going to define a new interface.
#undef INTERFACE 

//define IMyMath interface
#define INTERFACE IMyMath
DECLARE_INTERFACE_(IMyMath, IDispatch)
{
	//DECLARING pure virtual methods of grandparent inreFACE IUnknown // this pointer is extra parameter. ha jatoch cpp he lapvate.
	STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE; //hresult asel tr stdmethod.

	STDMETHOD_(ULONG, AddRef)(THIS) PURE; //	hresult sodun asel tr stdmehod_
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	//Defining pure virtual methods  of parent interface interface IDispatch
	STDMETHOD(GetTypeInfoCount)(THIS_ UINT*) PURE;
	STDMETHOD(GetTypeInfo)(THIS_ UINT, LCID, ITypeInfo**) PURE;
	STDMETHOD(GetIDsOfNames)(THIS_ REFIID, LPOLESTR*, UINT, LCID, DISPID*) PURE;
	STDMETHOD(Invoke)(THIS_ DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT * , EXCEPINFO*, UINT*) PURE;

	//DEFINING  pure virtual methods of child interface IMyMath
	STDMETHOD(SumOfTwoIntegers)(THIS_ int, int, int*) PURE;
	STDMETHOD(SubtractionOfTwoIntegers)(THIS_ int, int, int*) PURE;

};

//CLSID OF MyMath // {7379E19F-22EC-4037-8F2E-E3E6FA549D0A}
const CLSID CLSID_MyMath = { 0x7379e19f, 0x22ec, 0x4037, 0x8f, 0x2e, 0xe3, 0xe6, 0xfa, 0x54, 0x9d, 0xa };


// IID of ISum Interface // {E82B9B37-E8A1-44E7-A0AC-2465B7A8484D}
const IID IID_IMyMath = { 0xe82b9b37, 0xe8a1, 0x44e7, 0xa0, 0xac, 0x24, 0x65, 0xb7, 0xa8, 0x48, 0x4d };








