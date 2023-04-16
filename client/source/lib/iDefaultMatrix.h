#pragma once

#include "iunknown_.h"

class IDefaultMatrix : public IUnknown_
{
    public:
        virtual HRESULT_ __stdcall set_matrix() = 0;
        virtual HRESULT_ __stdcall mult_num() = 0;
        virtual HRESULT_ __stdcall addition() = 0;
        virtual HRESULT_ __stdcall subtraction() = 0;
        virtual HRESULT_ __stdcall exponentiation() = 0;
};

HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** object);
