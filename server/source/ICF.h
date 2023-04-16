#pragma once

#include "iunknown_.h"

class ICF : public IUnknown_{
    public:
    virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** object) = 0;
};