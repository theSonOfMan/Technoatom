//--------------------------------------
//! \file my_dump.h
//! \brief Contains dump and assert macros for different classes.\
A class must have a dump() method.
//! \author theSonOfMan, 2017
//--------------------------------------
#ifndef MY_DUMP_H
#define MY_DUMP_H

#include <ctime>
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>

std::string generate_file_name() {
    std::ostringstream file_path;
    file_path<<"../logs";
    char buf[100];
    std::time_t t = std::time(NULL);
    std::strftime( buf, sizeof(buf), "%Y-%m-%d.%H/%M/%S",std::localtime(&t));
    file_path<<buf<<".txt";
    return file_path.str();
}



class Logger{
public:

    static Logger& GetLogger();

    void WriteInLogger(std::string string_to_log);

    ~Logger();

    const std::string filename_;

private:
    Logger();

    std::ofstream file_;
};

Logger::Logger():filename_(generate_file_name())
{
    file_ = std::ofstream(filename_);
}

Logger::~Logger(){
    file_.close();
}

Logger& Logger::GetLogger(){
    static Logger logger;
    return logger;
}

void Logger::WriteInLogger(std::string string_to_log){
    file_<<string_to_log;
}


#ifdef LOG_VERBOSITY

#ifdef LOG_INFO_USAGE
#define LOG_INFO(p); \
    Logger::GetLogger().WriteInLogger(p);
#else
#define LOG_INFO(p);
#endif //LOG_INFO_USAGE


#ifdef LOG_WARNING_USAGE
#define LOG_WARNING(p); \
    Logger::GetLogger().WriteInLogger(p);
#else
#define LOG_WARNING(p);
#endif //LOG_WARNING_USAGE


#ifdef LOG_ERROR_USAGE
#define LOG_ERROR(p); \
    Logger::GetLogger().WriteInLogger(p);
#else
#define LOG_ERROR(p);
#endif //LOG_ERROR_USAGE

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
    dump_string<<"file: "<<__FILE__<<std::endl;\
    dump_string<<"line: "<<__LINE__<<std::endl;\
    dump_string<<"function: "<<__FUNCTION__<<std::endl;\
    dump_string<<dump()<<std::endl;

#define CONSOLE_OUTPUT \
    std::cerr<<dump_string.str();

#define FILE_OUTPUT \
    Logger::GetLogger().WriteInLogger(dump_string.str());\
    std::cerr<<"logs were put in "<<Logger::GetLogger().filename_;


#endif //MY_DUMP_H