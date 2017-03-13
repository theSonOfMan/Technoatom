//--------------------------------------
//!@file StackTest.cpp
//!@brief Contains tests for Stack class
//!@author theSonOfMan, 2017
//--------------------------------------
#include <iostream>
#include "stack_class.h"

#define TEST(what,case) printf("\nObject: " #what "    test: "#case"\n")


#ifndef NDEBUG
#define ASSERT_TEST(p,TestName)\
    if(!p){\
        assert(!"Object passed the "#TestName" test");\
    }\
    else{\
        printf("Object passed the "#TestName " test\n");\
    }
#else
#define ASSERT_TEST(p,TestName)
#endif


int main() {

    TEST(Stack,PushSingleNumber);
    {
        Stack s;
        ASSERT_TEST(s.push(46),PushSingleNumber);
        ASSERT_TEST((s.size()==1),SizeCheck);
    }

    TEST(Stack,CannotPushMore);
    {
        Stack s;
        for (int i = 0; i < s.capacity(); ++i)
            s.push(46);
        ASSERT_TEST(!s.push(46),CannotPushMore);
    }
//TODO  передалать тест
    TEST(Stack,PopFromEmptyStack);
    {
        Stack s;
        ASSERT_TEST(isnan(s.pop()),PopFromEmptyStack);
        s.push(46);
        s.pop();
        ASSERT_TEST(isnan(s.pop()),PopFromEmptyStack);
    }
//TODO  передалать тест
    TEST(Stack,TopFromEmptyStack);
    {
        Stack s;
        ASSERT_TEST(isnan(s.top()),TopFromEmptyStack);
    }
//TODO  передалать тест
    TEST(Stack,PopSingleNumber);
    {
        Stack s;
        s.push(46);
        ASSERT_TEST(!isnan(s.pop()),PopSingleNumber);
    }
//TODO  передалать тест
    TEST(Stack,CannotPopMore);
    {
        Stack s;
        while (s.push(46)) {}
        while (!isnan(s.top())){
            s.pop();
        }

        ASSERT_TEST(isnan(s.pop()),CannotPopMore);
    }
}