#include <iostream>
//#define USING_C_LIBRARY

#ifdef USING_C_LIBRARY   //if using c library libtest.so
extern "C"
{
#include "test.h"
}
#else      //if using cpp library  libtestcpp.so
#include "test.h"
#endif

int main()
{
    test();
    return 0;
}