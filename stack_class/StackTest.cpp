//--------------------------------------
//!@file StackTest.cpp
//!@brief Contains tests for Stack class
//!@author theSonOfMan, 2017
//--------------------------------------
#include <iostream>
#include "stack_class.h"
#include <cassert>


#define TEST(what,case) printf("\nObject: " #what "    test: "#case"\n");


#ifndef NDEBUG
#define ASSERT_TEST(p)\
    if(!(p)){\
        assert(!"Object passed the test");\
    }\
    else{\
        printf("Object passed the test\n");\
    }
#else
#define ASSERT_TEST(p,TestName)
#endif


int main() {

    TEST(Stack,PushSingleNumber)
    {
        Stack<int> s;
        ASSERT_TEST(s.push(46));
        ASSERT_TEST((s.size()==1));
    }

    TEST(Stack,CannotPushMore)
    {
        Stack<int> s;
        for (int i = 0; i < s.capacity(); ++i)
            s.push(46);
        ASSERT_TEST(!s.push(46));
    }

    TEST(Stack,PopFromEmptyStack)
    {
        Stack<int> s;
        ASSERT_TEST(!s.pop());
        s.push(46);
        ASSERT_TEST(s.pop());
        ASSERT_TEST(!s.pop());
    }

    TEST(Stack,TopFromStack)
    {
        Stack<int> s;
        s.push(46);
        ASSERT_TEST(s.top() != NULL);
        ASSERT_TEST(*(s.top()) == 46);
        s.pop();
        ASSERT_TEST(s.top() == NULL);
    }

    TEST(Stack,CannotPopMore)
    {
        Stack<int> s;
        for (int i=0; i<100; i++)
            s.push(46);
        for (int i=0; i<100; i++)
            s.pop();
        ASSERT_TEST(!s.pop());
    }
}