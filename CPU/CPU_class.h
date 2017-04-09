//
// Created by HOME on 05.04.17.
//

#ifndef CPU_CPU_CLASS_H
#define CPU_CPU_CLASS_H

#include "/Users/home/Technoatom/vector_class/vector_class.h"
#include "/Users/home/Technoatom/stack_class/stack_class.h"
#include <fstream>
#include <vector>

template <typename T>
class CPU{
    public:
    typedef T value_type;

    CPU();
    ~CPU();

    void read_commands_from_file(const std::string file_name);

    Vector<T> command_list_;

private:
    size_t command_quantity_;

    value_type x1_;
    value_type x2_;
    value_type x0_;
    value_type y1_;
    value_type y2_;
    value_type y0_;

};

#include "CPU_class.hpp"
#endif //CPU_CPU_CLASS_H
