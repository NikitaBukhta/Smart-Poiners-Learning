#include "gtest/gtest.h"    // google tests;
#include "unique_ptr"

using namespace smart_ptr;

const int CHECKED_NUMBER = 10;

TEST(UniquePtrTest, TestForReset){
    UniquePtr<int> unique(new int(CHECKED_NUMBER));
    unique.reset();
    ASSERT_EQ(unique.get(), nullptr);
}

TEST(UniquePtrTest, TestForDereference){
    UniquePtr<int> unique(new int(CHECKED_NUMBER));

    ASSERT_EQ(*unique, CHECKED_NUMBER);
}

TEST(UniquePtrTest, TestForMoving){
    UniquePtr<int> a (new int(CHECKED_NUMBER));
    auto b (std::move(a));

    ASSERT_EQ(a.get(), nullptr);
    ASSERT_EQ(*b, CHECKED_NUMBER);

    UniquePtr<int> c;
    c = std::move(b);

    ASSERT_EQ(b.get(), nullptr);
    ASSERT_EQ(*c, CHECKED_NUMBER);
}

TEST(UniquePtrTest, TestForOperatorArrow){
    struct Struct{
        int a;
        int b;
        int c;
    };

    UniquePtr<Struct> unique(new Struct({1, 2, 3}));
    ASSERT_EQ(unique->a, 1);
    unique->a = CHECKED_NUMBER;
    ASSERT_EQ(unique->a, CHECKED_NUMBER);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}