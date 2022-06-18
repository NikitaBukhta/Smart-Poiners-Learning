#include "gtest/gtest.h"
#include "shared_ptr"

#include <iostream>

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

TEST(SharedPtrTest, TestForManyPointers){
    const int checked_number = 10;
    SharedPtr<int> a (new int(checked_number));
    {
        SharedPtr<int> b (a);

        ASSERT_EQ(a.get(), b.get());
        ASSERT_EQ(a.use_count(), 2);
        ASSERT_EQ(b.use_count(), 2);
    }

    ASSERT_EQ(a.use_count(), 1);
}

TEST(SharedPtrTest, TestOperatorAssignment){
    const int checked_number = 10;
    SharedPtr<int> a (new int(checked_number));
    SharedPtr<int> b;

    ASSERT_EQ(b.get(), nullptr);
    b = a;
    ASSERT_EQ(a.get(), b.get());
    ASSERT_EQ(a.use_count(), b.use_count());
    ASSERT_EQ(a.use_count(), 2);
}

TEST(SharedPtrTest, TestMoveConstructor){
    const int checked_number = 10;
    SharedPtr<int> a (new int(checked_number));
    SharedPtr<int> b (std::move(a));

    ASSERT_EQ(*b.get(), checked_number);
    ASSERT_NE(a.get(), b.get());
    ASSERT_EQ(a.get(), nullptr);
    ASSERT_EQ(a.use_count(), 0);
}

TEST(SharedPtrTest, TestMoveOperatorAssignment){
    const int checked_number = 10;
    SharedPtr<int> a (new int(checked_number));
    SharedPtr<int> b;

    ASSERT_EQ(b.get(), nullptr);
    b = std::move(a);
    ASSERT_EQ(*b.get(), checked_number);
    ASSERT_NE(a.get(), b.get());
    ASSERT_EQ(a.get(), nullptr);
    ASSERT_EQ(a.use_count(), 0);
}

TEST(SharedPtr, TwoMorePtrs){
    SharedPtr<int> a (new int(5));
    SharedPtr<int> b (new int(5));

    ASSERT_EQ(a.use_count(), 1);
    ASSERT_EQ(b.use_count(), 1);
    ASSERT_NE(a.get(), b.get());
    ASSERT_EQ(*a.get(), *b.get());
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}