#include "gtest/gtest.h"
#include "shared_ptr"

#include <iostream>

using namespace smart_ptr;

const int CHECKED_NUMBER = 10;

TEST(SharedPtrTest, TestForRemoveOne){
    int * int_ptr;
    {
        SharedPtr<int> shared (new int(CHECKED_NUMBER));
        int_ptr = shared.get();

        ASSERT_EQ(*int_ptr, CHECKED_NUMBER);
    }

    ASSERT_NE(*int_ptr, CHECKED_NUMBER);
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
    SharedPtr<int> a (new int(CHECKED_NUMBER));
    {
        SharedPtr<int> b (a);

        ASSERT_EQ(a.get(), b.get());
        ASSERT_EQ(a.use_count(), 2);
        ASSERT_EQ(b.use_count(), 2);
    }

    ASSERT_EQ(a.use_count(), 1);
}

TEST(SharedPtrTest, TestOperatorAssignment){
    SharedPtr<int> a (new int(CHECKED_NUMBER));
    SharedPtr<int> b;

    ASSERT_EQ(b.get(), nullptr);
    b = a;
    ASSERT_EQ(a.get(), b.get());
    ASSERT_EQ(a.use_count(), b.use_count());
    ASSERT_EQ(a.use_count(), 2);
}

TEST(SharedPtrTest, TestMoveConstructor){
    SharedPtr<int> a (new int(CHECKED_NUMBER));
    SharedPtr<int> b (std::move(a));

    ASSERT_EQ(*b.get(), CHECKED_NUMBER);
    ASSERT_NE(a.get(), b.get());
    ASSERT_EQ(a.get(), nullptr);
    ASSERT_EQ(a.use_count(), 0);
}

TEST(SharedPtrTest, TestMoveOperatorAssignment){
    SharedPtr<int> a (new int(CHECKED_NUMBER));
    SharedPtr<int> b;

    ASSERT_EQ(b.get(), nullptr);
    b = std::move(a);
    ASSERT_EQ(*b.get(), CHECKED_NUMBER);
    ASSERT_NE(a.get(), b.get());
    ASSERT_EQ(a.get(), nullptr);
    ASSERT_EQ(a.use_count(), 0);
}

TEST(SharedPtrTest, TwoMorePtrs){
    SharedPtr<int> a (new int(5));
    SharedPtr<int> b (new int(5));

    ASSERT_EQ(a.use_count(), 1);
    ASSERT_EQ(b.use_count(), 1);
    ASSERT_NE(a.get(), b.get());
    ASSERT_EQ(*a.get(), *b.get());
}

TEST(SharedPtrTest, DereferenceObject){
    SharedPtr<int> a (new int(CHECKED_NUMBER));

    ASSERT_EQ(*a, CHECKED_NUMBER);
    ASSERT_EQ(*a, *a.get());
}

TEST(SharedPtrTest, TestArrowOperator){
    struct TestStruct{
        int a;
        int b;
        int c;
    };

    SharedPtr<TestStruct> test_struct (new TestStruct({1, 2, 3}));

    ASSERT_EQ((*test_struct).a, (*test_struct.get()).a);
    ASSERT_EQ(test_struct->a, 1);
    ASSERT_EQ(test_struct->b, 2);
    ASSERT_EQ(test_struct->c, 3);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}