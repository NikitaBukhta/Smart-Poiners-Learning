#include "gtest/gtest.h"
#include "shared_ptr"

using namespace smart_ptr;

TEST(SharedPtrTest, TestForRemoveOne){
    int * int_ptr;
    const int checked_number = 10;

    {
        SharedPtr<int> shared (new int(checked_number));
        int_ptr = shared.get();

        ASSERT_EQ(*int_ptr, checked_number);
    }

    ASSERT_NE(*int_ptr, checked_number);
}

TEST(SharedPtrTest, TestForRemoveArray){
    int * int_ptr;

    {
        SharedPtr<int> shared (new int[10]);
        int_ptr = shared.get();

        ASSERT_EQ(*int_ptr, 0);
        ASSERT_EQ(*(int_ptr + 1), 0);
    }

    ASSERT_NE(*int_ptr, 0);
    ASSERT_NE(*(int_ptr + 1), 0);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}