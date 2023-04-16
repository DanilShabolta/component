#include "DMF.h"

using namespace std;

DefaultMatricClassFactory::DefaultMatricClassFactory(){
    cout<<"DefaultMatricClassFactory::DefaultMatricClassFactory"<<endl;
    this->refCount = 0;
}

DefaultMatricClassFactory::~DefaultMatricClassFactory(){
    cout<<"DefaultMatricClassFactory::~DefaultMatricClassFactory"<<endl;
}


HRESULT_ DefaultMatricClassFactory::QueryInterface(const IID_& iid, void** object){
    cout<<"DefaultMatricClassFactory::QueryInterface"<<endl;
        if (iid == IID_IClassFactory_){
            *object = (IUnknown_*) (ICF*) this;
        }
        else if (iid == IID_IDefaultMatrixClassFactory){
            *object = (IUnknown_*) (IDefaultMatrixFactory*) this;
        }
        else{
            *object = NULL;
            return E_NOINTERFACE_;
        }

        this->AddRef();
        return refCount;
}

HRESULT_ DefaultMatricClassFactory::AddRef(){
    refCount++;
    return refCount;
}

HRESULT_ DefaultMatricClassFactory::Release(){
    refCount--;
    if (refCount == 0){
        delete this;
    }
    return refCount;
}

HRESULT_ DefaultMatricClassFactory::CreateInstance(const IID_& iid, void** object){
    cout<<"DefaultMatricClassFactory::CreateInstance"<<endl;
    IUnknown_* s = (IUnknown_*)(IDefaultMatrix*) new Server();

    s->AddRef();
    HRESULT_ res = s->QueryInterface(iid, object);
    s->Release();

    return res;
}

HRESULT_ DefaultMatricClassFactory::CreateInstance(const IID_& iid, void** object, int license[]){
    cout<<"DefaultMatricClassFactory::CreateInstance with license"<<endl;
    HRESULT_ res = E_NOCOMPONENT_;

    if (license != NULL){
        IUnknown_*s = (IUnknown_*)(IDefaultMatrix*) new Server();

        s->AddRef();
        res = s->QueryInterface(iid, object);
        s->Release();
    }
    return res;
}
//global
HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** object){
    cout<<"CreateIsntance"<<endl;

    ICF* s = NULL;
    HRESULT_ res = GetClassObject(clsid, IID_IClassFactory_, (void**) &s);

    if (res == S_OK_){
        if (iid == IID_IDefaultMatrix){
            IDefaultMatrix* dm = NULL;
            res = s->CreateInstance(iid, (void**) &dm);
            *object = (IUnknown_*)(IDefaultMatrix*) dm;
        }
        else if (iid == IID_IProMatrix){
            IProMatrix* pm = NULL;
            res = s->CreateInstance(iid, (void**) &pm);
            *object = (IUnknown_*)(IProMatrix*) pm;
        }
    }else{
        cout<<"CreateIsntance ERROR"<<endl;
    }
/*
    IUnknown_* s = NULL;
    if (clsid == CLSID_Server){
        s = (IUnknown_*)(IDefaultMatrix*) new Server();
    }else{
        *object = NULL;
        return E_NOCOMPONENT_;
    }
    s->AddRef();
    HRESULT_ res = s->QueryInterface(iid, object);
    s->Release;
*/
    return res;
}

// HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** object){
//     cout<<"GetClassObject"<<endl;
//     IUnknown_* s = NULL;
//     if (clsid == CLSID_DefaultMatrixClassFactory){
//         s = (IUnknown_*)(ICF*) new DefaultMatricClassFactory();
//     }else{
//         *object = NULL;
//         return E_NOCOMPONENT_;
//     }
//     s->AddRef();
//     HRESULT_ res = s->QueryInterface(iid, object);
//     s->Release();

//     return S_OK_;
// }

extern "C" HRESULT_ __stdcall __declspec(dllexport) GetClassObject(const CLSID_& clsid, const IID_& iid, void** object)
{
    std::cout<<"Global GetClassObject"<<std::endl;

    IUnknown_* s = NULL;

    if (clsid == CLSID_DefaultMatrixClassFactory)
    {
        s = (IUnknown_*) (ICF*) new DefaultMatricClassFactory();
    }
    else
    {
        *object = NULL;
        return E_NOCOMPONENT_;
    }

    s->AddRef();
    HRESULT_ res = s->QueryInterface(iid, object);
    s->Release();
    
    return S_OK_;
}


BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

