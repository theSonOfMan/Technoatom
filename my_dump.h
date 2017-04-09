//--------------------------------------
//! \file my_dump.h
//! \brief Contains dump and assert macros for different classes.\
A class must have a dump() method.
//! \author theSonOfMan, 2017
//--------------------------------------
#pragma once

#include <ctime>
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>

using std::ostringstream;
using std::endl;
using std::ofstream;
using std::string;

string dump_file_name() {
    ostringstream file_path;
    file_path<<"../dump";
    file_path<<time(NULL)<<".txt";
    return file_path.str();
}

ofstream dump_file(dump_file_name());

#define ASSERT_OK(p) \
do{\
    if (!(p)) {\
        DUMP_CREATION\
        std::cerr<<endl<<"Critical failure, program is going to close."<<endl;\
        {CONSOLE_OUTPUT}\
        {FILE_OUTPUT}\
        exit(1);\
    }\
} while (false);

#define DUMP_CREATION \
    ostringstream dump_string;\
    dump_string<<"file: "<<__FILE__<<endl;\
    dump_string<<"line: "<<__LINE__<<endl;\
    dump_string<<"function: "<<__FUNCTION__<<endl;\
    dump_string<<dump()<<endl;

#define CONSOLE_OUTPUT \
    std::cerr<<dump_string.str();

#define FILE_OUTPUT \
    string path = dump_file_name();\
    dump_file<<dump_string.str();\
    std::cerr<<"logs were put in "<<path;\
    dump_file.close();

