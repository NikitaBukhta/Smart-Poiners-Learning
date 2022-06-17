#include "test_class.h"

using namespace test;

TestClass::TestClass(void){
    _var = new int(1);

    std::cout << "Constructor" << std::endl;
}

TestClass::~TestClass(void){
    delete _var;

    std::cout << "Destructor" << std::endl;
}

TestClass::TestClass(const TestClass &other){
    this->_var = new int(*other._var);

    std::cout << "Coping costructor" << std::endl;
}

TestClass::TestClass(TestClass &&other){
    this->_var = other._var;
    other._var = nullptr;

    std::cout << "Moving costructor" << std::endl;
}

TestClass& TestClass::operator= (const TestClass &other){
    if (this != &other){
        delete this->_var;
        this->_var = new int(*other._var);
    }

    std::cout << "Assignment operator" << std::endl;

    return *this;
}

TestClass& TestClass::operator= (TestClass &&other){
    std::cout << "Movement operator" << std::endl;

    if (this != &other){
        delete this->_var;
        this->_var = other._var;
        other._var = nullptr;
    }

    return *this;
}

TestClass* TestClass::operator->(void){
    return this;
}

int TestClass::get_var(void){
    return *_var;
}

void TestClass::do_something(void){
    std::cout << "Do some magic" << std::endl;
}