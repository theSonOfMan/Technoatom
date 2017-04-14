#include <iostream>
#include "print.h"

int main() {
    int int_value = 46;
    double double_value = 0.46;
    std::string string_value = "forty six";

    print("int_value = #\ndouble_value = #", int_value, double_value);
    
    return 0;
}