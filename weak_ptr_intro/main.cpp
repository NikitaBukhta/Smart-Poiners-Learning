#include "test_class.h"

#include <iostream>

void test_1(void){
    std::cout << "test 1:" << std::endl;

    std::weak_ptr<int> wptr_0;
    std::cout << "weak_ptr got expired " << std::boolalpha
    << wptr_0.expired() << std::endl;

    std::shared_ptr<int> shrd_ptr1(new int(12));

    std::weak_ptr<int> wptr_1(shrd_ptr1);
    std::cout << "*wptr_1 acquired the_lock() == "
    << *wptr_1.lock() << std::endl;
    std::cout << "wptr is expired: " << std::boolalpha
              << wptr_1.expired() << std::endl;

    std::weak_ptr<int> wptr_2(wptr_1);
    std::cout << "*wptr_2 acquired the_lock() == "
    << *wptr_2.lock() << std::endl;

    std::weak_ptr<int> wptr_3(wptr_2);
    shrd_ptr1.reset();
    std::cout << "weak_ptr_3 got expired " << std::boolalpha
    << wptr_3.expired() << std::endl;

    std::cout << std::endl;
}

void test_2(void){
    auto shared = std::make_shared<int>();

    std::weak_ptr weak(shared);
    std::weak_ptr weak_2(shared);
    std::weak_ptr weak_3(shared);

    //std::cout << "weak_ptr:\t" << weak << std::endl;
    //std::cout << "*weak_ptr:\t" << *weak << std::endl;
    std::cout << "weak_ptr.lock():\t" << weak.lock() << std::endl;
    std::cout << "*weak_ptr.lock():\t" << *weak.lock() << std::endl;
    std::cout << "weak_ptr.use_count():\t" << weak.use_count() << std::endl;
    weak.reset();
    std::cout << "Reset()" << std::endl;
    std::cout << "weak_ptr.lock():\t" << weak.lock() << std::endl;
    //std::cout << "*weak_ptr.lock():\t" << *weak.lock() << std::endl;
    std::cout << "weak_ptr.use_count():\t" << weak.use_count() << std::endl;
    
    std::cout << "shared_ptr.use_count():\t" << shared.use_count() << std::endl;
}

int main(int argc, char **argv){
    //test_1();
    test_2();

    return 0;
}