#include <iostream>

#include "stack_class.h"

int main() {
    Stack<int> s;
    try{
        s.top();
    }
    catch (my_sp_exception& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}