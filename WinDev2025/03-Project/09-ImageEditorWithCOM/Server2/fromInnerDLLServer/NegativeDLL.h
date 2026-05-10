#pragma once

class INegative :public IUnknown //IMultipliction mnje IRajeshPradhan
{
public:
	//inherited fn 1)QueryInterface() 2) AddRef() 3) Release() from IUnknown

   //isumm
	virtual HRESULT _stdcall ApplyNegative(COLORREF originalpixelColor, COLORREF* negativeColor) = 0;
};


//CLSID OF CMultiplicationDevision // {8D259429-D813-42F2-B7D7-B7F167296F52}
const CLSID CLSID_Negative = { 0x8d259429, 0xd813, 0x42f2, 0xb7, 0xd7, 0xb7, 0xf1, 0x67, 0x29, 0x6f, 0x52 };



// IID of IMultiplication Interface // {347F5835-6BB6-4AEC-A022-9B810F2311F7}
const IID IID_INegative = { 0x347f5835, 0x6bb6, 0x4aec, 0xa0, 0x22, 0x9b, 0x81, 0xf, 0x23, 0x11, 0xf7 };













