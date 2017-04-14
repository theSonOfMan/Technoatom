#include <iostream>

#include "stack_class.h"

int main() {
    Stack<int> s;
    s.push(345);
    std::cout<<s.top()<<std::endl;
    std::cout<<s.pop();
    return 0;
}