#include <iostream>

#include "test_class.h"

void test_1(void){
    std::cout << "test1 " << std::endl;

    auto a_ptr = std::make_unique<test::TestClass>();
    std::unique_ptr<test::TestClass> b_ptr(a_ptr.get());

    b_ptr.reset();
    a_ptr.reset();

    std::cout << std::endl;
}

void test_2(void){
    std::cout << "test 2" << std::endl;

    std::unique_ptr<test::TestClass> a_ptr(new test::TestClass());
    std::unique_ptr<test::TestClass> b_ptr;

    b_ptr = std::move(a_ptr);

    auto ptr_to_object = b_ptr.get();

    //b_ptr.release();  // pointer is null and data is not free;
    //b_ptr.reset();    // pointer is null and data is free;

    std::cout << std::endl;
}

int main(int argc, char **argv){
    //test_1();
    test_2();

    return 0;
}