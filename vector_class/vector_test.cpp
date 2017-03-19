//--------------------------------------
//! \file vector_test.cpp
//! \brief Contains tests for vector class
//! \author theSonOfMan, 2017
//--------------------------------------

#include <iostream>
#include "vector_class.h"
#include <cassert>
#include <ctime>

// FIXME: вынеси эти макросы в библиотеку my_test.h

#define TEST(what,case) printf("\nObject: " #what "    test: "#case"\n");


#ifndef NDEBUG
#define ASSERT_TEST(p)\
    if(!(p)){\
        assert(!"Test failure");\
    }\
    else{\
        printf("Object passed the test\n");\
    }
#else
#define ASSERT_TEST(p,TestName)
#endif

// FIXME: не хватает теста на базовые операции добавления/извлечения элементов.

int main (){

    srand(time(NULL));

    TEST (Vector, NewMemoryAllocated)
    {
        Vector<int> vect1;
        ASSERT_TEST(vect1.data_pointer() != NULL);

        Vector<int> vect2(46);
        ASSERT_TEST(vect2.data_pointer() != NULL);

        Vector<int> copy_of_vect2 = vect2;
        ASSERT_TEST(copy_of_vect2.data_pointer() != NULL);
    }

    TEST(Vector, SwapTest)
    {
        Vector<int> vect1;
        Vector<int> vect2(46);
        vect2[0]=46;

        vect1.swap(vect2);
        bool p = (vect1.size()==46)&&(vect2.size()==0)&&(vect1[0]==46);
        ASSERT_TEST(p);
    }

    TEST(Vector, CopyTest)
    {
        Vector<int> vect1;
        Vector<int> vect2(46);

        for (int i=0; i<vect2.size(); i++){
            vect2[i] = rand();
        }

        vect1=vect2;
        bool p = vect1.size()==vect2.size();

        for (int i=0; i<vect1.size()&&p; i++){
            if (vect1[i] != vect2[i])
                p = false;
        }

        ASSERT_TEST(p);
    }

    return 0;
}
