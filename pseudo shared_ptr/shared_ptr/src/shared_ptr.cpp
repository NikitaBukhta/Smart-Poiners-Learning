#include "shared_ptr.h"

using namespace smart_ptr;

template<typename T>
SharedPtr<T>::SharedPtr(T *ptr){
    this->_ptr = ptr;

    this->_count = new ullong(1);
}

template<typename T>
SharedPtr<T>::~SharedPtr(void){
    reset();
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &other){
    this->_ptr = other._ptr;
    this->_count = other._count;
    ++(*this->_count);
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T> &&other){
    this->_ptr = other._ptr;
    this->_count = other._count;
    
    other._ptr = nullptr;
    other._count = nullptr;
}

template<typename T>
void SharedPtr<T>::operator= (const SharedPtr<T> &other){
    this->_ptr = other._ptr;
    this->_count = other._count;
    ++(*this->_count);
}

template<typename T>
void SharedPtr<T>::operator= (SharedPtr<T> &&other){
    this->_ptr = other._ptr;
    this->_count = other._count;
    
    other._ptr = nullptr;
    other._count = nullptr;
}

template<typename T>
bool SharedPtr<T>::operator== (const SharedPtr<T> &other) const{
    return this->_ptr == other._ptr;
}

template<typename T>
bool SharedPtr<T>::operator!= (const SharedPtr<T> &other) const{
    return this->_ptr != other._ptr;
}

template<typename T>
T& SharedPtr<T>::operator* (void){
    return *_ptr;
}

template<typename T>
T* SharedPtr<T>::operator-> (void){
    return _ptr;
}

template<typename T>
T* SharedPtr<T>::get(void){
    return _ptr;
}

template<typename T>
ullong SharedPtr<T>::use_count(void){
    if (_count == nullptr){
        return 0;
    }

    return *_count;
}

template<typename T>
void SharedPtr<T>::reset(void){
    if (_count != nullptr && --(*_count) == 0){
        delete[] _ptr;
    }
    
    _count = nullptr;
    _ptr = nullptr;
}