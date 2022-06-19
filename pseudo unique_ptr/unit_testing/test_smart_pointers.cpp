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

/* Description:
 * This function test operators == and !=;
 * Will terminate work of the program;
 */
bool test_for_equals_and_not(void){
    const UniquePtr<int> a_uptr (new int(1));
    UniquePtr<int> b_uptr (a_uptr.get());
    const UniquePtr<int> c_uptr (new int(1));

    bool ret;
    ret = a_uptr == b_uptr;
    ret = a_uptr == b_uptr.get() && ret;
    ret = a_uptr != c_uptr && ret;
    ret = a_uptr != c_uptr.get() && ret;

    std::cout << "Test for == and != is " << std::boolalpha 
              << ret << std::endl;

    return ret;
}

TEST(UniquePtrTest, TestForEqualsAndNot){
    // Check if all operators works right and throw program terminates;
    ASSERT_EXIT(ASSERT_TRUE(test_for_equals_and_not()), 
        testing::KilledBySignal(SIGABRT), ".*");
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}