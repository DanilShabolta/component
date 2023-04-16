#include "server.h"

#include <iostream>
using namespace std;

HRESULT_ Server::AddRef()
{
    refCount++;
    return refCount;
}

HRESULT_ Server::Release()
{
    refCount--;
    if (refCount == 0)
    {
        delete this;
    }
    
    return refCount;
}


Server::Server() 
{
  cout << "Server::Constructor" << endl;
  refCount = 0;
}

Server::~Server() 
{
  cout << "Server::Destructor" << endl;  
}

HRESULT_ __stdcall Server::QueryInterface(const IID_& iid, void** object)
{
   cout << "Server QueryInterface:" << iid << endl;

   if (iid==IID_IUnknown_)
   {
     *object = (IUnknown_*)(IDefaultMatrix*) this;
   }
   else if (iid== IID_IDefaultMatrix)
   {
     *object = static_cast<IDefaultMatrix*>(this);
   }
   else if (iid==IID_IProMatrix)
   {
     *object = static_cast<IProMatrix*>(this);
   }
   else
   {
     *object = NULL;
     return E_NOINTERFACE_;
   }
   return S_OK_;
}

	
HRESULT_ __stdcall Server::find_determinant() 
{	 	    		
  return S_OK_;
}

HRESULT_ __stdcall Server::set_matrix() 
{	 	    		
  cout << "Server set matrix" << endl;
  cin >> M;
  cin >> N;
	int matrix [M][N];
  for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> matrix[i][j];
	};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++){
			cout << matrix[i][j];
			};
		cout << " " << endl;
	}; 	   
	return matrix[M][N];
  return S_OK_;
}

HRESULT_ __stdcall Server::mult_num() 
{
	cin >> num;
  int matrix[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			matrix[i][j] *= num;
	};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++){
			cout << matrix[i][j];
			};
		cout << " " << endl;
	};	
  return S_OK_;
}

HRESULT_ __stdcall Server::addition()
{	 	    		
  return S_OK_;
}

HRESULT_ __stdcall Server::subtraction()
{	 	    		
  return S_OK_;
}

HRESULT_ __stdcall Server::exponentiation()
{	 	    		
  return S_OK_;
}

HRESULT_ __stdcall Server::transposition()
{	 	    		
  return S_OK_;
}

HRESULT_ __stdcall Server::rank()
{	 	    		
  return S_OK_;
}

HRESULT_ __stdcall Server::reverse()
{	 	    		
  return S_OK_;
}

HRESULT_ __stdcall Server::minor()
{	 	    		
  return S_OK_;
}
