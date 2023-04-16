#include <windows.h>
#include <iostream>

using HRESULT_ = int;
using IID_ = int;
using CLSID_ = int;
using ULONG_ = int;

const int IID_IUnknown_ = 1;
const int IID_IDefaultMatrix = 2;
const int IID_IProMatrix = 3;

const int IID_IClassFactory_ = 11;
const int IID_IDefaultMatrixClassFactory = 12;

const int S_OK_ = 0;
const int E_NOINTERFACE_ = 1;
const int E_NOCOMPONENT_ = 2;

const int CLSID_Server = 1;
const int CLSID_DefaultMatrixClassFactory = 1;

using namespace std;

typedef HRESULT_ __stdcall (*FunctionType) (const CLSID_&, const IID_&, void**);

extern "C" HRESULT_ __stdcall __declspec(dllexport) CreateInstance(const CLSID_& clsid, const IID_& iid, void** object)
{
    return 0;
}

extern "C" HRESULT_ __stdcall __declspec(dllexport) GetClassObject(const CLSID_& clsid, const IID_& iid, void** object){
    
    const char* path;

    if(clsid == CLSID_Server){
        path = "./dll/lib/server.dll";
    }
    else{
        return E_NOCOMPONENT_;
    }

    HINSTANCE h = LoadLibrary(path);

    if (!h)
    {
           std::cout<<"No dll!!!"<<std::endl;
    }

    FunctionType GCO=(FunctionType) GetProcAddress(h,"GetClassObject");

    if (!GCO)
    {
          std::cout << "No dll function" << std::endl;
    }

    return GCO(clsid, iid, object);

}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{	
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            cout << "DLL STARTED" << endl;
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            cout << "NO DLL FUNC" << endl;
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}