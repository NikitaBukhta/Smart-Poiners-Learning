#include <memory>
#include <iostream>

#include "test_class.h"

void func_with_pointer(test::TestClass *tc){
    std::cout << tc->get_var() << std::endl;
}

void test_1(void){
    std::cout << "Test 1 started!" << std::endl;

    auto a = std::make_unique<test::TestClass>();
    std::cout << "Var field value: " << a->get_var() << std::endl;

    std::cout << std::endl;
}

void test_2(void){
    std::cout << "Test 2 started!" << std::endl;

    auto a = std::make_unique<test::TestClass>();
    
    /* Compile error!
     * function needs simple pointer, not smart
     */
    //func_with_pointer(a);
    func_with_pointer(a.get());
    func_with_pointer(a.get());

    /* Warning! There could be memory leak, because
     * that returned pointer to the memory and 
     * lose ownership after a call;
     */
    func_with_pointer(a.release());

    /* zsh: segmentation fault
     * because release method returns the pointer
     * to the memory space and lose ownership after a call;
     */
    //func_with_pointer(a.release());

    std::cout << std::endl;
}

void test_3(void){
    std::cout << "Test 3 started!" << std::endl;

    auto a = std::make_unique<test::TestClass>();

    func_with_pointer(a.get());
    a.reset();
    func_with_pointer(a.get());

    std::cout << std::endl;
}

int main(int argc, char **argv){
    test_1();
    test_2();
    test_3();

    return 0;
}