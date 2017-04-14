//
// Created by HOME on 05.04.17.
//

#ifndef CPU_CPU_CLASS_H
#define CPU_CPU_CLASS_H

#include "/Users/home/Technoatom/vector_class/vector_class.h"
#include "/Users/home/Technoatom/stack_class/stack_class.h"
#include "/Users/home/Technoatom/print_lib/print.h"
#include "/Users/home/Technoatom/CPU/cmd_codes.h"
#include <fstream>
#include <iostream>
#include <vector>

//TODO:  обнулить
template <typename T>
struct memory{
    T x0;
    T x1;
    T x2;
    T y0;
    T y1;
    T y2;
};

template <typename T>
class CPU{
    public:
    typedef T value_type;

    CPU();
    ~CPU();

    void read_commands_from_file(const std::string file_name);

    void run_commands();

    Vector<T> command_list_;
    Stack<T> command_stack_;

    memory<T> memory_;

private:
    size_t command_quantity_;
};

#include "CPU_class.hpp"
#endif //CPU_CPU_CLASS_H

