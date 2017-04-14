#include <iostream>
#include "/Users/home/Technoatom/print_lib/print.h"
#include "CPU_class.h"

int main() {
    CPU<int> cpu;
    cpu.read_commands_from_file("command_file.txt");
//    cpu.command_list_.print_data();
    cpu.memory_.x1 = 100;
    cpu.memory_.x2 = 200;
    cpu.run_commands();
    print("\nx0 = #", cpu.memory_.x0);
    return 0;
}