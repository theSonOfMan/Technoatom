//--------------------------------------
//!@file StackTest.cpp
//!@brief Contains tests for Stack class
//!@author theSonOfMan, 2017
//--------------------------------------

#include <iostream>
#include "stack_class.h"

#define TEST(what,case) printf("\nObject: " #what "    test: "#case"\n")

// TEST(a == b, c)


#ifndef NDEBUG
#define ASSERT_EQ(p,TestName)\
    if(!p){\
        assert(!"Object passed the "#TestName" test");\
    }\
    else{\
        printf("Object passed the "#TestName " test\n");\
    }
#else
#define ASSERT_EQ(p,TestName)
#endif


int main() {

    TEST(Stack,PushSingleNumber);
    {
        Stack s;
        ASSERT_EQ(s.push(46),PushSingleNumber);
        ASSERT_EQ((s.size()==1),SizeCheck);
    }

    TEST(Stack,CannotPushMore);
    {
        Stack s;
        for (int i = 0; i < s.capacity(); ++i)
            s.push(46);
        ASSERT_EQ(!s.push(46),CannotPushMore);
    }

    TEST(Stack,PopFromEmptyStack);
    {
        Stack s;
        ASSERT_EQ(isnan(s.pop()),PopFromEmptyStack);
        s.push(46);
        s.pop();
        ASSERT_EQ(isnan(s.pop()),PopFromEmptyStack);
    }

    TEST(Stack,TopFromEmptyStack);
    {
        Stack s;
        ASSERT_EQ(isnan(s.top()),TopFromEmptyStack);
    }

    TEST(Stack,PopSingleNumber);
    {
        Stack s;
        s.push(46);
        ASSERT_EQ(!isnan(s.pop()),PopSingleNumber);
    }

    TEST(Stack,CannotPopMore);
    {
        Stack s;
        while (s.push(46)) {}
        while (!isnan(s.top())){
            s.pop();
        }

        ASSERT_EQ(isnan(s.pop()),CannotPopMore);
    }
}