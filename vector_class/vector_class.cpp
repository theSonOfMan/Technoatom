//--------------------------------------
//! \file vector_class.cpp
//! \brief Contains definitions of vector class functions
//! \author theSonOfMan, 2017
//--------------------------------------

#include "vector_class.h"
#include "../my_dump.h"


#define NO_GETCHAR true

#if NO_GETCHAR
#define GETCHAR
#else
#define GETCHAR \
    getchar();
#endif

#define PRINTS false
#if PRINTS
#define VECTOR_BIRTH \
    std::cout<<"Я родился в участке памяти "<<this<<std::endl;
#define VECTOR_DEATH \
    std::cout<<"Я умер в участке памяти "<<this<<std::endl;
#define NEW_MEMORY \
    std::cout<<"я new, я выделил память здесь: "<<where_to_create<<std::endl;
#else
#define VECTOR_BIRTH
#define VECTOR_DEATH
#define NEW_MEMORY
#endif

Vector::Vector(): size_(0){
    VECTOR_BIRTH
    data_ = new value_type[size_];
    ASSERT_OK(data_ != NULL)
    GETCHAR
}

Vector::Vector(size_t vector_size): size_(vector_size){
    VECTOR_BIRTH
    data_ = new value_type[size_];
    ASSERT_OK(data_ != NULL)
    for (int i=0; i<size_; i++)
        data_[i]=0;
    GETCHAR
}

Vector::Vector(const Vector &that):
        size_ (that.size_),
        data_ (new value_type[that.size_])
{
    VECTOR_BIRTH
    ASSERT_OK(data_ != NULL)
    std::copy(that.data_, that.data_ + that.size_, data_);
    ASSERT_OK(data_ != NULL)
    GETCHAR
}

Vector::~Vector() {
    VECTOR_DEATH
    ASSERT_OK(data_ != NULL)
    delete[] data_;
    GETCHAR
}

size_t Vector::size() const{
    return size_;
}

Vector::value_type* Vector::data_pointer() const{
    return data_;
}

void Vector::print_data() {
    ASSERT_OK(data_ != NULL)
    for (int iter=0; iter < size_; iter++)
        std::cout<<data_[iter]<<' ';
    std::cout<<std::endl;
}

Vector::value_type& Vector::operator[] (size_t index){
    ASSERT_OK(index < size_)
    ASSERT_OK(data_ != NULL)
    return data_[index];
}

void Vector::swap(Vector &that) {

    size_t temp_size = size_;
    size_ = that.size_;
    that.size_ = temp_size;

    value_type* temp_data = data_;
    data_ = that.data_;
    that.data_ = temp_data;

}

const Vector& Vector::operator = (const Vector&that) {
    if (&that == this) return *this;
    this->~Vector();
    new (this) Vector(that);
    GETCHAR
    return *this;
}

void* Vector::operator new (size_t size, void* where_to_create) {
    NEW_MEMORY
    GETCHAR
    return where_to_create;
}

std::string Vector::dump(){
    ostringstream out_string;
    out_string<<"size: "<<size_<<endl;
    out_string<<"data pointer: "<<data_<<endl;
    out_string<<"data:"<<endl;
    if (data_!=NULL)
        for (int iter=0; iter < size_; iter++)
            out_string<<iter<<':'<<data_[iter]<<endl;
    return out_string.str();
}