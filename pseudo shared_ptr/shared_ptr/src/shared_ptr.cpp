#include "shared_ptr.h"

using namespace smart_ptr;

template<typename T>
SharedPtr<T>::SharedPtr(T *ptr){
    this->_ptr = ptr;
}

template<typename T>
SharedPtr<T>::~SharedPtr(void){
    delete[] _ptr;
}

template<typename T>
int* SharedPtr<T>::get(void){
    return _ptr;
}