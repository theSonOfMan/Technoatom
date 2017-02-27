//--------------------------------------
//!@file stack_class.h
//!@brief Implements a stack class
//!@author theSonOfMan, 2017
//--------------------------------------

#include <cassert>
#include <fstream>
#include <math.h>

//--------------------------------------
//@def A macro to check if stack isn't damaged by other functions
//--------------------------------------
#define ASSERT_OK()\
    if (!ok())\
    {\
        dump();\
        assert(!"object is ok");\
    }\

//--------------------------------------
//@class Stack
//@brief A Stack class
/*!
 * A Stack class created by theSonOfMan for Technoatom courses
 */
//--------------------------------------

class Stack{
    public:

    typedef float value_type;//<type of the value stored in the stack

    //--------------------------------------
    //!Shows the top value of the stack
    //!@return top value (NaN if stack is empty)
    //--------------------------------------
    value_type top();

    //--------------------------------------
    //!Shows if stack is empty
    //!@return bool-type result of an operation (true of false)
    //--------------------------------------
    bool empty();

    //--------------------------------------
    //!Deletes the top value from the Stack
    //!@return popped value (NaN if stack is empty)
    //--------------------------------------
    value_type pop();

    //--------------------------------------
    //!Pushes the value to the stack
    //!@param value to be pushed
    //!@return success of the operation
    //--------------------------------------
    bool push(value_type value_to_push);

    //--------------------------------------
    //!Returns the size of the stack
    //!@return the size of the stack
    //--------------------------------------
    size_t size();

    //--------------------------------------
    //!Returns the capacity of the stack
    //!@return the capacity of the stack
    //--------------------------------------
    size_t capacity();

    private:

    Stack();
    ~Stack(){ }

    static const size_t capacity_=6;

    value_type data_[capacity_];
    size_t size_;

    bool ok();
    void dump();


};

Stack::Stack(){
    size_=0;
}

Stack::value_type Stack::top(){
    ASSERT_OK();
    if (this->empty()){
        ASSERT_OK();
        return __nan();
    }
    value_type top_value;
    top_value = data_[size_-1];
    ASSERT_OK();
    return top_value;
}

bool Stack::push(value_type value_to_push){
    ASSERT_OK();
    if (size_>=capacity_) {
        ASSERT_OK();
        return false;
    }
    data_[size_]=value_to_push;
    size_++;
    ASSERT_OK();
    return true;
}

Stack::value_type Stack::pop(){
    ASSERT_OK();
    value_type pop_value;
    if (this->empty()) {
        ASSERT_OK();
        return __nan();
    }
    pop_value = data_[--size_];
    ASSERT_OK();
    return pop_value;
}

bool Stack::empty(){
    ASSERT_OK();
    if (size_==0) {
        ASSERT_OK();
        return true;
    }
    ASSERT_OK();
    return false;
}

size_t Stack::size(){
    ASSERT_OK();
    return size_;
}

size_t Stack::capacity() {
    ASSERT_OK();
    return capacity_;
}

bool Stack::ok(){
    return size_<=capacity_;
}

void Stack::dump(){
    ofstream dump_file;
    dump_file.open("/Users/home/Technoatom/stack_class/dump.txt");
    dump_file<<"size = "<<size_<<endl<<"data:"<<endl;
    for (int i=0;i<capacity_;i++) {
        dump_file<<i<<' ';
        dump_file << data_[i] << endl;
    }
    dump_file.close();
}
