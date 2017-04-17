//--------------------------------------
//! \file my_dump.h
//! \brief Contains Logger class ang log macros. \
Contains dump and assert macros for different classes. \
A class must have a dump() method to use an assert macro.
//! \author theSonOfMan, 2017
//--------------------------------------
#ifndef MY_DUMP_H
#define MY_DUMP_H

#include <ctime>
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>
#include <exception>
#include "print_lib/print.h"

std::string generate_file_name() {
    std::ostringstream file_path;
    file_path<<"../../program logs/logs";
    char buf[100];
    std::time_t t = std::time(NULL);
    std::strftime( buf, sizeof(buf), "%Y-%m-%d.%H:%M:%S",std::localtime(&t));
    file_path<<buf<<".txt";
    return file_path.str();
}

class my_sp_exception : public std::exception{
public:  

    my_sp_exception(const char* info);

    const char* what();

    ~my_sp_exception(){}

private:
    const char* info_;
};

my_sp_exception::my_sp_exception(const char* info): info_(info)
{}

const char* my_sp_exception::what(){
    return info_;
}

class Logger{
public:

    static Logger& GetLogger();

    void WriteInLogger(std::string str);

    template <typename T, typename ...Args>
    void WriteInLogger(std::string str, T val, Args... args);

    template <typename T>
    void WriteInLogger(T val);

    ~Logger();

    void LogTime();

    const std::string filename_;

private:

    Logger();
    std::clock_t program_start_;
    std::ofstream file_;
};

Logger::Logger():
    filename_(generate_file_name()),
    program_start_(std::clock())
{
    file_ = std::ofstream(filename_);
    file_ << "Program init" << std::endl;
}

Logger::~Logger(){
    file_.close();
}

Logger& Logger::GetLogger(){
    static Logger logger;
    return logger;
}

void Logger::WriteInLogger(std::string str){

    file_ << str;
}

template <typename T, typename ...Args>
void Logger::WriteInLogger(std::string str, T val, Args... args){
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

template <typename T>
void Logger::WriteInLogger(T val){
    file_ << val;
}

void Logger::LogTime(){
    file_ << (std::clock() - program_start_) / (double) CLOCKS_PER_SEC << "s\t : \t";
}

#ifdef LOG_VERBOSITY

    #ifdef LOG_INFO_USAGE
        #define LOG_INFO(p); \
            Logger::GetLogger().LogTime();\
            Logger::GetLogger().WriteInLogger(p);\
            Logger::GetLogger().WriteInLogger("\n");
    #else
        #define LOG_INFO(p);
    #endif //LOG_INFO_USAGE


    #ifdef LOG_WARNING_USAGE
        #define LOG_WARNING(p); \
            Logger::GetLogger().LogTime();\
            Logger::GetLogger().WriteInLogger(p);\
            Logger::GetLogger().WriteInLogger("\n");
    #else
        #define LOG_WARNING(p);
    #endif //LOG_WARNING_USAGE


    #ifdef LOG_ERROR_USAGE
        #define LOG_ERROR(p); \
            Logger::GetLogger().LogTime();\
            Logger::GetLogger().WriteInLogger(p);\
            Logger::GetLogger().WriteInLogger("\n");
    #else
        #define LOG_ERROR(p);
    #endif //LOG_ERROR_USAGE

#else 

    #define LOG_ERROR
    #define LOG_INFO
    #define LOG_WARNING

#endif //LOG_VERBOSITY


#define ASSERT_OK(p) \
do{\
    if (!(p)) {\
        DUMP_CREATION\
        std::cerr<<std::endl<<"Critical failure, program is going to close."<<std::endl;\
        {CONSOLE_OUTPUT}\
        {FILE_OUTPUT}\
        exit(1);\
    }\
} while (false);

#define DUMP_CREATION \
    std::ostringstream dump_string;\
    dump_string << "Critical failure" << std::endl;\
    dump_string << "file: " << __FILE__ << std::endl;\
    dump_string << "line: " << __LINE__ << std::endl;\
    dump_string << "function: " << __FUNCTION__ << std::endl;\
    dump_string << dump()<<std::endl;

#define CONSOLE_OUTPUT \
    std::cerr<<dump_string.str();

#define FILE_OUTPUT \
    Logger::GetLogger().LogTime();\
    Logger::GetLogger().WriteInLogger(dump_string.str());\
    std::cerr<<"logs were put in "<<Logger::GetLogger().filename_;


#endif //MY_DUMP_H