#include <iostream>
#include "smart_pointers.h"
#include "../vector_class/vector_class.h"
#include "../stack_class/stack_class.h"

int main() {
    {
//        Unique_ptr<Stack> pointer = new Stack;
//        pointer->push(46);
//        pointer->push(64);
//        std::cout << pointer->top();
//        pointer->pop();
//        std::cout << pointer->top();
    }

    {
        //Unique_ptr<Vector<int>> vect_pointer = new Vector<int>;
        Vector<int>* vect = new Vector<int>(10);
        
    }
    return 0;
}