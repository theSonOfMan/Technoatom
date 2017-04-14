#ifndef CPU_CPU_CLASS_HPP
#define CPU_CPU_CLASS_HPP

template <typename T>
CPU<T>::CPU(): command_list_(Vector<T>(100)), command_quantity_(0){
//    std::cout<<std::endl<<command_list_.data_pointer()<<std::endl;
}

template <typename T>
CPU<T>::~CPU() {
//    print("destructor\n");
}

template <typename T>
void CPU<T>::read_commands_from_file(const std::string file_name) {
    std::ifstream commands_input(file_name); //TODO: проверить открытие
    while (commands_input >> command_list_[command_quantity_])
    {
        printf("%d ", command_list_[command_quantity_]);
        command_quantity_++;
    }
    print("\n");
//    std::cout<<command_list_.data_pointer()<<std::endl;
    commands_input.close();
}
/*TODO:
COMMAND(ADD, onAdd, 0)
COMMAND(ADD, onAdd, 0)
COMMAND(ADD, onAdd, 0)
COMMAND(ADD, onAdd, 0)
COMMAND(ADD, onAdd, 0)
COMMAND(ADD, onAdd, 0)

#define COMMAND(name, func, args_num) \
     case name: \
        func(get_args(args_num)); \
        break;

#include "commands.h"
#undef

enum {
#define COMMAND(name, a, b) name,
#include "commands.h"
#undef
};
*/
template <typename T>
void CPU<T>::run_commands() {
    for (int cmd_number = 0; cmd_number < command_quantity_; cmd_number++){
        T command = command_list_[cmd_number];
        print("command = #\n", command);
        switch (command) {

            case ADD_CMD_CODE:
                command_stack_.push(command_stack_.pop() + command_stack_.pop());
//                print("addition completed\n");
                break;

            case DIV_CMD_CODE:
                command_stack_.push(command_stack_.pop() / command_stack_.pop());
                break;

            case MULTIPLY_CMD_CODE:
                command_stack_.push(command_stack_.pop() * command_stack_.pop());
                break;

            case DEDUCT_CMD_CODE:
                command_stack_.push(command_stack_.pop() - command_stack_.pop());
                break;

            case MOD_CMD_CODE:
                command_stack_.push(command_stack_.pop() % command_stack_.pop());
                break;

            case PUSH_CMD_CODE:
                cmd_number++;
                command = command_list_[cmd_number];
                switch (command){

                    case X0_CODE:
                        command_stack_.push(memory_.x0);
                        break;

                    case X1_CODE:
                        command_stack_.push(memory_.x1);
                        print("x1 = # pushed\n",memory_.x1);
                        break;

                    case X2_CODE:
                        command_stack_.push(memory_.x2);
                        print("x2 = # pushed\n", memory_.x2);
                        break;

                    case Y0_CODE:
                        command_stack_.push(memory_.y0);
                        break;

                    case Y1_CODE:
                        command_stack_.push(memory_.y1);
                        break;

                    case Y2_CODE:
                        command_stack_.push(memory_.y2);
                        break;

                    default:
                        break;
                }
                break;

            case PUSH_CONST_CMD_CODE:
                cmd_number++;
                command_stack_.push(command_list_[cmd_number]);
                break;

            case POP_CMD_CODE:
                cmd_number++;
                command = command_list_[cmd_number];
                switch (command){

                    case X0_CODE:
                        memory_.x0 = command_stack_.pop();
//                        print("x0 = # put in memory", memory_.x0);
                        break;

                    case X1_CODE:
                        memory_.x1 = command_stack_.pop();
                        break;

                    case X2_CODE:
                        memory_.x2 = command_stack_.pop();
                        break;

                    case Y0_CODE:
                        memory_.y0 = command_stack_.pop();
                        break;

                    case Y1_CODE:
                        memory_.y1 = command_stack_.pop();
                        break;

                    case Y2_CODE:
                        memory_.y2 = command_stack_.pop();
                        break;

                    default:
                        break;
                }
                break;

            case TOP_CMD_CODE:
                cmd_number++;
                command = command_list_[cmd_number];
                switch (command){
                    case X0_CODE:
                        memory_.x0 = command_stack_.top();
                        break;

                    case X1_CODE:
                        memory_.x1 = command_stack_.top();
                        break;

                    case X2_CODE:
                        memory_.x2 = command_stack_.top();
                        break;

                    case Y0_CODE:
                        memory_.y0 = command_stack_.top();
                        break;

                    case Y1_CODE:
                        memory_.y1 = command_stack_.top();
                        break;

                    case Y2_CODE:
                        memory_.y2 = command_stack_.top();
                        break;

                    default:
                        break;
                }

            case JMP_CMD_CODE:
                cmd_number++;
                cmd_number = command_list_[cmd_number]-1;
                break;

            case JE_CMD_CODE:
                if (command_stack_.pop() == command_stack_.pop()){
                    cmd_number++;
                    cmd_number = command_list_[cmd_number]-1;
                }
                break;

            case JA_CMD_CODE:
                if (command_stack_.pop() > command_stack_.pop()){
                    cmd_number++;
                    cmd_number = command_list_[cmd_number]-1;
                }
                break;

            case JAE_CMD_CODE:
                if (command_stack_.pop() >= command_stack_.pop()){
                    cmd_number++;
                    cmd_number = command_list_[cmd_number]-1;
                }
                break;

            case JB_CMD_CODE:
                if (command_stack_.pop() < command_stack_.pop()){
                    cmd_number++;
                    cmd_number = command_list_[cmd_number]-1;
                }
                break;

            case JBE_CMD_CODE:
                if (command_stack_.pop() <= command_stack_.pop()){
                    cmd_number++;
                    cmd_number = command_list_[cmd_number]-1;
                }
                break;

            case JNE_CMD_CODE:
                if (command_stack_.pop() != command_stack_.pop()){
                    cmd_number++;
                    cmd_number = command_list_[cmd_number]-1;
                }
                break;

            case CALL_CMD_CODE:
                cmd_number++;
                cmd_number = command_list_[cmd_number]-1;
                break;

            case RET_CMD_CODE:
                cmd_number++;
                cmd_number = command_list_[cmd_number]-1;
                break;

            case END_CMD_CODE:
                cmd_number = command_quantity_+1;
                break;

            default:
                break;
        }

    }
}

#endif //CPU_CPU_CLASS_HPP
