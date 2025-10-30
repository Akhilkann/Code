#include <iostream>
using namespace std;

void test() {}
void test(int a)            { cout << __func__ << " int " << a << endl; }
void test(short int b)      { cout << __func__ << " short int " << b << endl; }
void test(const char* s)         { cout << __func__ << " "<<s << endl; }
void test(const char* s, int a)  { cout << __func__ <<" "<< s << "," << a << endl; }
void test(float x)          { cout << __func__ << " float " << x << endl; }
void test(double x)         { cout << __func__ << " double " << x << endl; }
void test(auto a)           { cout<<__func__<<" auto "<<a<<endl;}

int main()
{
    test();
    test(5);
    test(static_cast<short int>(4)); //need to type cast to short int otherwise call test(int a)
    test("Hello");
    test("Hello", 5);
    test(static_cast<float>(3.1));  //default is double need to type cast to float
    test(4.456);
    test('c');


    return 0;
}

/*
run command -> nm executable

compiler encoded function names for the above test functions
0000000000001511 W _Z4testIcEvT_
00000000000012dc T _Z4testPKc
0000000000001341 T _Z4testPKci
0000000000001434 T _Z4testd
00000000000013ce T _Z4testf
0000000000001214 T _Z4testi
0000000000001276 T _Z4tests
0000000000001209 T _Z4testv

*/