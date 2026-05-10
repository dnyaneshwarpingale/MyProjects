#pragma once

class IDesaturation :public IUnknown //ISum mnje IRajeshPradhan
{
public:
	//inherited fn 1)QueryInterface() 2) AddRef() 3) Release() from IUnknown

   //isumm
	virtual HRESULT _stdcall ApplyDesaturation(COLORREF originalpixelColor, COLORREF* dsaturatedColor) = 0;
};

class ISepia :public IUnknown //ISubstract  mnje IRajeshPradhan
{
public:
	//inherited fn 1)QueryInterface 2) AddRef 3) Release from IUnknown

	//isub
	virtual HRESULT _stdcall ApplySepia(COLORREF originalpixelColor, COLORREF* sepiaColor) = 0;
};

class INegative :public IUnknown //IMultipliction mnje IRajeshPradhan
{
public:
	//inherited fn 1)QueryInterface() 2) AddRef() 3) Release() from IUnknown

   //isumm
	virtual HRESULT _stdcall ApplyNegative(COLORREF originalpixelColor, COLORREF* negativeColor) = 0;
};

//CLSID OF CDesaturationSepia// // {401ACB83-0E9B-4930-9A2C-A19484F5EBFC}
const CLSID CLSID_DesaturationSepia = { 0x401acb83, 0xe9b, 0x4930, 0x9a, 0x2c, 0xa1, 0x94, 0x84, 0xf5, 0xeb, 0xfc };



// IID of IDesaturation Interface // {03148751-8A5C-4BBE-9C7F-0068CFEE3725}
const IID IID_IDesaturation = { 0x3148751, 0x8a5c, 0x4bbe, 0x9c, 0x7f, 0x0, 0x68, 0xcf, 0xee, 0x37, 0x25 };



// IID of ISepia Interface // {5E2E1846-D3F9-49B2-BCDD-D89E1A9F5603}
const IID IID_ISepia = { 0x5e2e1846, 0xd3f9, 0x49b2, 0xbc, 0xdd, 0xd8, 0x9e, 0x1a, 0x9f, 0x56, 0x3 };

// IID of IMultiplication Interface // {347F5835-6BB6-4AEC-A022-9B810F2311F7}
const IID IID_INegative = { 0x347f5835, 0x6bb6, 0x4aec, 0xa0, 0x22, 0x9b, 0x81, 0xf, 0x23, 0x11, 0xf7 };
