#pragma once

#include <iostream>
#include <Windows.h>

#include "iDefaultMatrix.h"
#include "iProMatrix.h"

class Server : public IDefaultMatrix, public IProMatrix
{
    private:
        int refCount;
        int N;
        int M;
        int M1;
        int M2;
        int num;
        int matrix_ = set_matrix();
    public:
        Server();
        
        virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** object);
        virtual HRESULT_ __stdcall AddRef();
        virtual HRESULT_ __stdcall Release();

        virtual HRESULT_ __stdcall set_matrix();
        virtual HRESULT_ __stdcall mult_num();
        virtual HRESULT_ __stdcall addition();
        virtual HRESULT_ __stdcall subtraction();
        virtual HRESULT_ __stdcall exponentiation();

        virtual HRESULT_ __stdcall find_determinant();
        virtual HRESULT_ __stdcall transposition();
        virtual HRESULT_ __stdcall rank();
        virtual HRESULT_ __stdcall reverse();
        virtual HRESULT_ __stdcall minor();
        
        ~Server();

};
