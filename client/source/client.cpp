#include "wrapper.h"
#include <iostream>

using namespace std;

int main() {
	cout << "Client start" << endl;			
	
	FunctionType f;
	const char* path = "./client/source/lib/manager.dll";

    HINSTANCE h = LoadLibrary(path);

	try{
	 	//cout<<"default class factory"<<endl;
		BServer b;
		f = (FunctionType) GetProcAddress(h, "set_matrix");
	 }catch(AServer& a){
		cout<<a.GetMessage()<<endl;
	 }
	
	return 0;
}