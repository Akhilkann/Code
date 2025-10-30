#include<iostream>

using namespace std;
int global_int;
char global_char;
float global_float;
double global_double;
bool global_bool;

int main()
{
int local_int;
char local_char;
float local_float;
double local_double;
bool local_bool;


cout<<"size_of int="<< sizeof(int)<<endl;
cout<<"size_of char="<< sizeof(char)<<endl;
cout<<"size_of float="<< sizeof(float)<<endl;
cout<<"size_of double="<< sizeof(double)<<endl;
cout<<"size_of bool="<< sizeof(bool)<<endl;

cout<<"address of global_int="<< (&global_int)<<endl;
cout<<"address of global_char="<< ((void*)&global_char)<<endl;
cout<<"address of global_float="<< (&global_float)<<endl;
cout<<"address of global_double="<< (&global_double)<<endl;
cout<<"address of global_bool="<< (&global_bool)<<endl;


cout<<"address of local_int="<< (&local_int)<<endl;
cout<<"address of local_char="<< ((void*)&local_char)<<endl;
cout<<"address of local_float="<< (&local_float)<<endl;
cout<<"address of local_double="<< (&local_double)<<endl;
cout<<"address of local_bool="<< (&local_bool)<<endl;


return 0;
}
