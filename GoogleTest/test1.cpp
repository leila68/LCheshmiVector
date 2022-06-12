//
// Created by internet on 6/12/2022.
//
#include "lib/googletest/include/gtest/gtest.h"
#include "../CCustom_vector.h"

int main (){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
};

TEST(SuiteName1, ExampleTest) {
   CCustom_vector<int> vec1;
   vec1.push_back(1);
   EXPECT_EQ(vec1.at(0), 1);
}

class SuiteName2 : public ::testing::Test {
public :
    virtual void SetUp () override {
        auto temp  = CCustom_vector<int>{1, 2, 3, 4};
        obj = temp;
    }
    CCustom_vector<int> obj;
};


TEST_F(SuiteName2, ExampleTest){
    EXPECT_EQ(obj.at(1), 2);
}

TEST_F(SuiteName2, RangeCheck){
    EXPECT_THROW(obj.at(10), std::out_of_range);
}
