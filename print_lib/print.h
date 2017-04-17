//------------------------------------
//! \file print.h
//! \brief contains 'print' function
//! \author theSonOfMan, 2017
//------------------------------------

#ifndef PRINT_LIB_PRINT_H
#define PRINT_LIB_PRINT_H

#include <string>
#include <iostream>

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

void print (std::string str){
    std::cout << str;
}

template <typename T, typename ...Args>
void print (std::string str, T val, Args... args){
    int i = 0;
    while (i < str.length()){
        if (str[i] != '#')
            printf("%c",str[i]);
        else{
            std::cout << val;
            str = str.erase(0,i+1);
            print(str, args...);
            break;
        }
        i++;
    }
}
#endif //PRINT_LIB_PRINT_H
