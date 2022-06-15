#include "gtest/gtest.h"    // google tests;
#include "test_class.h"

void double_owner(void){
    auto a_ptr = std::make_unique<test::TestClass>();
    std::unique_ptr<test::TestClass> b_ptr(a_ptr.get());

    b_ptr.reset();
    a_ptr.reset();
}

TEST(UniquePtrTest, TestForDoubleOwnerCrash){
    ASSERT_EXIT(double_owner(), testing::KilledBySignal(SIGABRT), ".*");
}

void second_owner_with_move(void){
    std::unique_ptr<test::TestClass> a_ptr;
    std::unique_ptr<test::TestClass> b_ptr(std::move(a_ptr));
}

TEST(UniquePtrTest, TestForMoveNoFatal){
    ASSERT_NO_FATAL_FAILURE(second_owner_with_move());
}

void second_owner_reset_both(void){
    std::unique_ptr<test::TestClass> a_ptr;
    std::unique_ptr<test::TestClass> b_ptr(std::move(a_ptr));

    a_ptr.reset();
    b_ptr.reset();
    a_ptr.reset();
}

TEST(UniquePtrTest, TestForMoveDeleteNoFatal){
    ASSERT_NO_FATAL_FAILURE(second_owner_reset_both());
}

TEST(UniquePtrTest, GetPointerMakeReset){
    std::unique_ptr<test::TestClass> a_ptr(new test::TestClass());
    auto ptr_to_object = a_ptr.get();

    a_ptr.reset();  // clear data and make nullptr;
    ASSERT_EXIT(ptr_to_object->get_var(), testing::KilledBySignal(SIGSEGV), ".*");
}

TEST(UniquePtrTest, GetPointerMakeRelease){
    std::unique_ptr<test::TestClass> a_ptr(new test::TestClass());
    auto ptr_to_object = a_ptr.get();

    a_ptr.release();  // no clear data and make nullptr;
    ASSERT_NO_FATAL_FAILURE(ptr_to_object->get_var());
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}