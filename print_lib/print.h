//------------------------------------
//! \file print.h
//! \brief contains 'print' function
//! \author theSonOfMan, 2017
//------------------------------------

#ifndef PRINT_LIB_PRINT_H
#define PRINT_LIB_PRINT_H

void print (const char* str){
    while (*str)
        printf("%c", *str++);
}

template <typename T, typename ...Args>
void print (const char*str, T val, Args... args){
    while (*str){
        if (*str!='#')
            printf("%c",*str++);
        else{
            std::cout << val;
            print(str+1, args...);
            break;
        }
    }
}

#endif //PRINT_LIB_PRINT_H
