#include<iostream>
#include"my_program.hpp"
int add(int a, int b)
{
    return a+b;
}
void test(UT_Mock *UT,int a,int b)
{
    int ret=UT->add(a,b);
}