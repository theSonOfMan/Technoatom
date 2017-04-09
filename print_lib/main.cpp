#include <iostream>
#include "print.h"

int main() {
    int int_value = 46;
    double double_value = 0.46;
    std::string string_value = "forty six";
    print("int: #\ndouble: #\nstring: #\n", int_value, double_value, string_value);
    return 0;
}