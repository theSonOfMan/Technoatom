#include <iostream>
#include "CPU_class.h"

int main() {
    CPU<int> cpu;
    cpu.read_commands_from_file("output.txt");
//    cpu.command_list_.print_data();
    return 0;
}