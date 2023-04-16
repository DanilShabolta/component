#include <iostream>

#include "iDefaultMatrix.h"
#include "server.h"

HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** object)
{
    IUnknown_* s = NULL;

    if (clsid == CLSID_Server)
    {
        s = (IUnknown_*) (IDefaultMatrix*) new Server();
    }
    else
    {
        *object = NULL;
        return E_NOCOMPONENT_;
    }

    s->AddRef();
    HRESULT_ res = s->QueryInterface(iid, object);
    s->Release();
    
    return res;
}
