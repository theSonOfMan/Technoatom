//--------------------------------------
//!@file stack_class.h
//!@brief Implements a stack class
//!@author theSonOfMan, 2017
//--------------------------------------
#include <cassert>
#include <fstream>
#include <math.h>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using std::ofstream;
using std::endl;
using std::to_string;
using std::cout;
using std::ostringstream;
using std::string;

#define CONSOLE_OUTPUT 0
#define FILE_OUTPUT 1

#define DUMP_CREATION \
    ostringstream dump_string;\
    dump_string<<"file: "<<__FILE__<<endl;\
    dump_string<<"line: "<<__LINE__<<endl;\
    dump_string<<"function: "<<__FUNCTION__<<endl;

#if CONSOLE_OUTPUT
#define DUMP_OUTPUT \
    cout<<dump_string.str();
#elif FILE_OUTPUT
#define DUMP_OUTPUT \
    ostringstream file_path;\
    file_path<<"/Users/home/Technoatom/stack_class/dump";\
    file_path<<time(NULL)<<".txt";\
    ofstream fout(file_path.str());\
    fout<<dump_string.str();
#endif

#define ASSERT_OK()\
do{\
    if (!ok()) {\
        DUMP_CREATION\
        DUMP_OUTPUT\
    }\
    else {}\
    if(!ok())\
        assert(false);\
} while (false);
//--------------------------------------
//@class Stack
//@brief A Stack class
/*!
 * A Stack class created by theSonOfMan for Technoatom courses
 */
//--------------------------------------

class Stack{
    public:

    //--------------------------------------
    //!Standart constructor for Stack class
    //--------------------------------------
    Stack();

    //--------------------------------------
    //!Standart destructor for Stack class
    //--------------------------------------
    ~Stack(){ }

    typedef float value_type; //<type of the value stored in the stack

    //--------------------------------------
    //!Shows the top value of the stack
    //!@param variable which can contain the top value
    //!@return success of the operation
    //--------------------------------------
    bool top(value_type& top_value);
    //TODO: возвращает нулевой указатель NULL.

    //--------------------------------------
    //!Shows if stack is empty
    //!@return bool-type result of an operation (true of false)
    //--------------------------------------
    bool empty();

    //--------------------------------------
    //!Deletes the top value from the Stack
    //!@param variable which can contain the popped value
    //!@return success of the operation
    //--------------------------------------
    bool pop();

    //--------------------------------------
    //!Pushes the value to the stack
    //!@param value to be pushed
    //!@return success of the operation
    //--------------------------------------
    bool push(const value_type& value_to_push);

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

    bool ok();
    void dump();

    void assert_test(){
        size_=capacity_+1;
        ASSERT_OK();
    }

    private:

    static const size_t capacity_=6;
    value_type data_[capacity_];

    size_t size_;


};

Stack::Stack(){
    size_=0;
}

bool Stack::top(value_type &top_value){
    ASSERT_OK();
    if (this->empty()){
        ASSERT_OK();
        return false;
    }
    top_value = data_[size_-1];
    ASSERT_OK();
    return true;
}

bool Stack::push(const value_type& value_to_push){
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

bool Stack::pop(){
    ASSERT_OK();
    if (this->empty())
        return false;
    --size_;
    ASSERT_OK();
    return true;
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
    cout<<"size = "<<size_<<endl<<"data:"<<endl;
    for (size_t inc; inc < capacity_; inc++){
        cout<<inc<<":  "<<data_[inc]<<endl;
    }
}