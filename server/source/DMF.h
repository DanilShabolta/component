#pragma once

#include "ICF.h"
#include "server.h"
#include "IDMF.h"

#include <iostream>

class DefaultMatricClassFactory : public ICF, public IDefaultMatrixFactory{
    private:
        int refCount;
    public:
        DefaultMatricClassFactory();

        virtual HRESULT_ __stdcall (QueryInterface(const IID_& iid, void** object));
        virtual HRESULT_ __stdcall AddRef();
        virtual HRESULT_ __stdcall Release();

        virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** object);

        virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** object, int license[]);

        ~DefaultMatricClassFactory();
};

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);