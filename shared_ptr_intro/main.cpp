#include "test_class.h"

#include <iostream>
#include <vector>

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

// check addresses after copiing in vector;
void test_3(void){
    std::cout << "test 3:" << std::endl;

    std::vector<std::shared_ptr<int>> v {
        std::make_shared<int>(1),
        std::make_shared<int>(2),
        std::make_shared<int>(3)
    };

    std::vector<std::shared_ptr<int>> v2;
    std::remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (std::shared_ptr<int> s){
        return *s == 2;
    });

    std::cout << "v1 addresses: " << std::endl;
    for (const auto& s : v){
        std::cout << *s << std::endl;
    }

    std::cout << "v2 addresses: " << std::endl;
    for (const auto& s : v2){
        std::cout << *s << std::endl;
    }

    std::cout << std::endl;
}

int main(int argc, char **argv){
    test_3();

    return 0;
}