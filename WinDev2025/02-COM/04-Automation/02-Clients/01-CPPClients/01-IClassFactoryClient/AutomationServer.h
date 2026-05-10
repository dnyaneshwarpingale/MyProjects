#pragma once

class IMyMath : public IDispatch
{
public:
	//pure virtual
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0;

	//pure virtual
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0;
};


//CLSID OF MyMath // {7379E19F-22EC-4037-8F2E-E3E6FA549D0A}
const CLSID CLSID_MyMath = { 0x7379e19f, 0x22ec, 0x4037, 0x8f, 0x2e, 0xe3, 0xe6, 0xfa, 0x54, 0x9d, 0xa };


// IID of ISum Interface // {E82B9B37-E8A1-44E7-A0AC-2465B7A8484D}
const IID IID_IMyMath = { 0xe82b9b37, 0xe8a1, 0x44e7, 0xa0, 0xac, 0x24, 0x65, 0xb7, 0xa8, 0x48, 0x4d };






