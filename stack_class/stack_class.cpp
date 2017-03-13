#include "stack_class.h"

Stack::Stack(): size_(0){}

const Stack::value_type* Stack::top(){
    ASSERT_OK(!ok());
    if (this->empty()){
        ASSERT_OK(!ok());
        return NULL;
    }
    ASSERT_OK(!ok());
    return &(data_[size_-1]);
}

bool Stack::push(const value_type& value_to_push){
    ASSERT_OK(!ok());
    if (size_>=capacity_) {
        ASSERT_OK(!ok());
        return false;
    }
    data_[size_]=value_to_push;
    size_++;
    ASSERT_OK(!ok());
    return true;
}

bool Stack::pop(){
    ASSERT_OK(!ok());
    if (this->empty())
        return false;
    --size_;
    ASSERT_OK(!ok());
    return true;
}

bool Stack::empty(){
    ASSERT_OK(!ok());
    if (size_==0) {
        ASSERT_OK(!ok());
        return true;
    }
    ASSERT_OK(!ok());
    return false;
}

size_t Stack::size(){
    ASSERT_OK(!ok());
    return size_;
}

size_t Stack::capacity() {
    ASSERT_OK(!ok());
    return capacity_;
}

bool Stack::ok(){
    return size_<=capacity_;
}

string Stack::dump(){
    ostringstream out_string;
    out_string<<"size: "<<size_<<endl;
    for (int i=0;i<size_;i++){
        out_string<<i<<": "<<data_[i]<<endl;
    }
    return out_string.str();
}