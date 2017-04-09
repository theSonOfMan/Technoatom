//
// Created by HOME on 27.03.17.
//

#ifndef SMART_POINTERS_SMART_POINTERS_H
#define SMART_POINTERS_SMART_POINTERS_H

template <typename T>
class Unique_ptr{
public:
    typedef T value_type;

    Unique_ptr(T* new_ptr);
    ~Unique_ptr();

    value_type& operator * ();

    value_type* operator -> ();

private:
    value_type* pointer_;
};


template <typename T>
Unique_ptr<T>::Unique_ptr(T* new_ptr):
    pointer_(new_ptr)
{}

template <typename T>
Unique_ptr<T>::~Unique_ptr() {
    delete pointer_;
}

template <typename T>
typename Unique_ptr<T>::value_type& Unique_ptr<T>::operator * (){
    return *pointer_;
}

template <typename T>
typename Unique_ptr<T>::value_type* Unique_ptr<T>::operator -> (){
    return pointer_;
}

#endif //SMART_POINTERS_SMART_POINTERS_H
