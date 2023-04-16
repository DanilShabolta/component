#include "wrapper.h"

using namespace std;

AServer::AServer(const char* msg)
{
    this->msg = msg;
}

const char* AServer::GetMessage()
{
    return msg;
}

BServer::BServer()
{
    ICF* MCF = NULL;

    const char* path = "./client/source/lib/manager.dll";

    HINSTANCE h = LoadLibrary(path);

    if(!h){
        cout << "No DLL" << endl;
        return;
    }
    

    FunctionType GCO = (FunctionType) GetProcAddress(h, "GetClassObject");

    if (!GCO)
    {
          std::cout << "No dll function" << std::endl;
          return;
    }


    HRESULT_ res = GCO(CLSID_DefaultMatrixClassFactory, IID_IClassFactory_, (void**) &MCF);

    if (res == E_NOCOMPONENT_)
    {
        throw AServer("Error: Unsupported component");
    }
    else if (res == E_NOINTERFACE_)
    {
        throw AServer("Error: Unsupported interface");
    }
    else if (res != S_OK_)
    {
        throw AServer("Error: Unknown error");
    }

    dm = NULL;
    res = MCF->CreateInstance(IID_IDefaultMatrix, (void**) &dm);

    pm = NULL;
    res = dm->QueryInterface(IID_IProMatrix, (void**) &dm);
    if (res != S_OK_)
    {
        dm->Release();
        if (res == E_NOINTERFACE_)
        {
            throw AServer("Error: Unsupported interface");
        }
        else
        {
            throw AServer("Error: Unknown error");
        }
    }

    MCF->Release();
}

BServer::BServer(int license[])
{
    IDefaultMatrixFactory* MCF = NULL;

    const char* path = "./client/source/lib/manager.dll";

    HINSTANCE h = LoadLibrary(path);

    if(!h){
        cout << "No DLL" << endl;
        return;
    }

    FunctionType GCO = (FunctionType) GetProcAddress(h, "GetClassObject");

    if (!GCO)
    {
          std::cout << "No dll function" << std::endl;
          return;
    }

    HRESULT_ res = GCO(CLSID_DefaultMatrixClassFactory, IID_IDefaultMatrixClassFactory, (void**) &MCF);
    if (res == E_NOCOMPONENT_)
    {
        throw AServer("Error: Unsupported component");
    }
    else if (res == E_NOINTERFACE_)
    {
        throw AServer("Error: Unsupported interface");
    }
    else if (res != S_OK_)
    {
        throw AServer("Error: Unknown error");
    }

    dm = NULL;
    res = MCF->CreateInstance(IID_IDefaultMatrix, (void**) &dm, license);

    if (res != S_OK_)
    {
        throw AServer("Error: wrong license");
    }

    pm = NULL;
    res = dm->QueryInterface(IID_IProMatrix, (void**) &pm);
    if (res != S_OK_)
    {
        dm->Release();
        if (res == E_NOINTERFACE_)
        {
            throw AServer("Error: Unsupported interface");
        }
        else
        {
            throw AServer("Error: Unknown error");
        }
    }

    MCF->Release();
}

HRESULT_ __stdcall BServer::set_matrix()
{
    return dm->set_matrix();
}

HRESULT_ __stdcall BServer::mult_num()
{
    return dm->mult_num();
}


BServer::~BServer()
{
    dm->Release();
    pm->Release();
}
