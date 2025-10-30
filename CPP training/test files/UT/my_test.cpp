#include"my_program.cpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>


TEST(AddTest, PositiveNumbers)
{
    Derived_UT_Mock obj;
     EXPECT_CALL(obj,add(2,4)).WillOnce(::testing::Return(6));
     test(&obj,2,4);
    //ASSERT_EQ(obj.add(2, 4), 6);
}
TEST(AddTest, NegativeNumbers)
{
    Derived_UT_Mock obj;
    int x=0;
    EXPECT_CALL(obj,add(-1,-2)).WillOnce(::testing::Return(-3));
    //test(&obj,2,4);
    x=obj.add(-1,-2);
    ASSERT_EQ(x,-3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*connand to run the test file
g++ -I/usr/src/googletest/googlemock/include -L/usr/src/googletest/googletest/include my_test.cpp -lgmock -lgtest -lpthread -o a
*/