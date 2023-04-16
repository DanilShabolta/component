#pragma once

#include "iunknown_.h"

class IProMatrix : public IUnknown_
{
    public:
        virtual HRESULT_ __stdcall set_matrix() = 0;
        virtual HRESULT_ __stdcall find_determinant() = 0;
        virtual HRESULT_ __stdcall transposition() = 0;
        virtual HRESULT_ __stdcall rank() = 0;
        virtual HRESULT_ __stdcall reverse() = 0;
        virtual HRESULT_ __stdcall minor() = 0;
};