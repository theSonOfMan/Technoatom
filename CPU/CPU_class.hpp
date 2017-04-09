template <typename T>
CPU<T>::CPU(): command_list_(Vector<T>(100)), command_quantity_(0){
    std::cout<<std::endl<<command_list_.data_pointer();
}

template <typename T>
CPU<T>::~CPU() {
//    printf("destructor\n");
//    command_list_.~Vector();
}

template <typename T>
void CPU<T>::read_commands_from_file(const std::string file_name) {
    std::ifstream commands_input(file_name);

    while (commands_input >> command_list_[command_quantity_])
    {
//        printf("%d ", command_list_[command_quantity_]);
        command_quantity_++;
    }
//    std::cout<<command_list_.data_pointer();
    commands_input.close();
}