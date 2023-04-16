#pragma once

#include "lib/iDefaultMatrix.h"
#include "lib/iProMatrix.h"
#include "lib/iunknown_.h"
#include "lib/ICF.h"
#include "lib/IDMF.h"

#include <windows.h>
#include <iostream>

typedef HRESULT_ __stdcall (*FunctionType) (const CLSID_&, const IID_&, void**);

class AServer
{
    private:
        const char* msg;
    public:
        AServer(const char* msg);
        const char* GetMessage();
};

class BServer
{
    private:
        IDefaultMatrix* dm;
        IProMatrix* pm;
        BServer(const BServer&) {};
        BServer& operator=(const BServer&) {return *this;};
    public:
        BServer();
        BServer(int license[]);

        virtual HRESULT_ __stdcall set_matrix();
        virtual HRESULT_ __stdcall mult_num();

        ~BServer();
};