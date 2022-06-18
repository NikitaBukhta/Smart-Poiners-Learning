#include "unique_ptr.h"

using namespace smart_ptr;

template <typename T>
UniquePtr<T>::UniquePtr(T *ptr){
    this->_ptr = ptr;
}

template <typename T>
UniquePtr<T>::~UniquePtr(void){
    delete[] _ptr;
}

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T> &&other){
    this->_ptr = other._ptr;
    other._ptr = nullptr;
}

template <typename T>
void UniquePtr<T>::operator= (UniquePtr<T> &&other){
    this->_ptr = other._ptr;
    other._ptr = nullptr;
}

template <typename T>
T& UniquePtr<T>::operator* (void) const noexcept{
    return *_ptr;
}

template <typename T>
T* UniquePtr<T>::get(void) const noexcept{
    return _ptr;
}

template <typename T>
void UniquePtr<T>::reset(T *ptr) noexcept{
    delete[] this->_ptr;
    this->_ptr = ptr;
}