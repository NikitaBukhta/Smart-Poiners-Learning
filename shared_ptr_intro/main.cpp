#include "test_class.h"

#include <iostream>

// check count of pointers to the memory space;
void test_1(void){
    std::cout << "Test 1:" << std::endl;

    auto a_ptr = std::make_shared<test::TestClass>();
    auto b_ptr = a_ptr;

    std::cout << a_ptr.use_count() << std::endl;

    std::cout << std::endl;
}

// test for swapping;
void test_2(void){
    std::cout << "test 2" << std::endl;

    auto a_ptr = std::make_shared<test::TestClass>();
    auto b_ptr = a_ptr;

    auto c_ptr = std::make_shared<test::TestClass>();

    std::shared_ptr<test::TestClass> null_ptr (nullptr);

    c_ptr.swap(a_ptr);

    std::cout << a_ptr.use_count() << std::endl;
    std::cout << b_ptr.use_count() << std::endl;
    std::cout << c_ptr.use_count() << std::endl;
    std::cout << null_ptr.use_count() << std::endl;

    std::cout << std::endl;
}

int main(int argc, char **argv){
    //std::cout << sizeof(std::shared_ptr<test::TestClass>) << std::endl;
    test_2();

    return 0;
}