#include<iostream>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

class UT_Mock
{
    public:
    UT_Mock();
    ~UT_Mock();
    virtual int add(int a,int b){return a+b;}
};
UT_Mock::UT_Mock() {}
UT_Mock::~UT_Mock() {}  // Even if it's empty, define it
class Derived_UT_Mock:public UT_Mock
{
    public:
    MOCK_METHOD(int,add,(int a,int b),(override));
};