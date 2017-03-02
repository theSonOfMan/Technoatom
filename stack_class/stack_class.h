//--------------------------------------
//!@file stack_class.h
//!@brief Implements a stack class
//!@author theSonOfMan, 2017
//--------------------------------------
#include <cassert>
#include <fstream>
#include <math.h>

using std::ofstream;
using std::endl;
using std::to_string;
using std::cout;

#define ASSERT_OK()\
    do{\
       if (!ok())\
           {\
               DUMP_OUTPUT\
                assert(!"object is ok");\
           }\
    } while (!ok());

#define DUMP_OUTPUT \
    cout<<"file: "<<__FILE__<<endl;\
    cout<<"line: "<<__LINE__<<endl;\
    cout<<"function: "<<__FUNCTION__<<endl;\


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
    // FIXME: Корректно обработать эту ситуацию для разных типов - сделано

    //--------------------------------------
    //!Pushes the value to the stack
    //!@param value to be pushed
    //!@return success of the operation
    //--------------------------------------
    bool push(const value_type& value_to_push);
    // FIXME: Используй константный указатель - сделано
    //

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