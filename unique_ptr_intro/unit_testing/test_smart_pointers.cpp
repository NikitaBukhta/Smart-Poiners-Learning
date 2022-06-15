#include "gtest/gtest.h"    // google tests;
#include "test_class.h"

TEST(TestUniquePointer, TestCallingObjectMethod){
    auto a = std::make_unique<test::TestClass>();

    ASSERT_NO_THROW(a->get_var());
}

TEST(TestUniquePointer, TestGettingObject){
    auto a = std::make_unique<test::TestClass>();
    
    ASSERT_NO_FATAL_FAILURE(a.get()->get_var());
    ASSERT_NO_FATAL_FAILURE(a.get()->get_var());

    /*             Warning! 
     * There must be memory leak, because
     * that returned pointer to the memory and 
     * lose ownership after a call;
     */
    ASSERT_NO_FATAL_FAILURE(a.release()->get_var());
    
    /* Must kill process because the unique_pointer lose ownership after
     * previous call;
     */
    ASSERT_EXIT(a.release()->get_var(), testing::KilledBySignal(SIGSEGV), ".*");
}

TEST(TestUniquePointer, RemoveDataFromSmartPointer){
    auto a = std::make_unique<test::TestClass>();

    ASSERT_NO_FATAL_FAILURE(a.get()->get_var());

    // clear data from smart pointer (destructor must be called);
    a.reset();

    ASSERT_EXIT(a.get()->get_var(), testing::KilledBySignal(SIGSEGV), ".*");
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}