//--------------------------------------
//!@file stack_class.h
//!@brief Implements a stack class
//!@author theSonOfMan, 2017
//--------------------------------------
#pragma once

#include <fstream>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include "/Users/home/Technoatom/my_dump.h"

using std::ofstream;
using std::endl;
using std::to_string;
using std::ostringstream;
using std::string;

//--------------------------------------
//@class Stack
//@brief A Stack class
/*!
 *!A Stack class created by theSonOfMan for Technoatom courses
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
    //!@return pointer on the value
    //--------------------------------------
    const value_type* top();

    //--------------------------------------
    //!Shows if stack is empty
    //!@return bool-type result of an operation (true of false)
    //--------------------------------------
    bool empty();

    //--------------------------------------
    //!Deletes the top value from the Stack
    //!@return bool-type result of an operation (true of false)
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

    //--------------------------------------
    //!Checks if stack is ok
    //!@return bool-type result
    //--------------------------------------
    bool ok();

    //--------------------------------------
    //!Returns information about the stack
    //!@return string, which contains the information
    //--------------------------------------
    string dump();

//    void assert_test(){
//        size_=capacity_+1;
//        ASSERT_OK(!ok());
//    }


    private:

    static const size_t capacity_=6;
    value_type data_[capacity_];

    size_t size_;
};

