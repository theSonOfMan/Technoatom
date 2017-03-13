//--------------------------------------
//! \file my_dump.h
//! \brief Contains dump and assert macros for different classes.\
//! a class must have a dump() method.
//! \author theSonOfMan, 2017
//--------------------------------------

#pragma once

#include <ctime>
#include <cassert>
#include <sstream>
#include <fstream>

using std::ostringstream;
using std::endl;
using std::ofstream;

#define ASSERT_OK(p) \
do{\
    if (!(p)) {\
        DUMP_CREATION\
        DUMP_OUTPUT\
    }\
    else {/*Написать эту ересь было хорошо обдуманным решением. Не бейте нас. Пожалуйста*/}\
    if(!(p))\
        assert(false);\
} while (false);

#define CONSOLE_OUTPUT 0
#define FILE_OUTPUT 1

#define DUMP_CREATION \
    ostringstream dump_string;\
    dump_string<<"file: "<<__FILE__<<endl;\
    dump_string<<"line: "<<__LINE__<<endl;\
    dump_string<<"function: "<<__FUNCTION__<<endl;\
    dump_string<<dump()<<endl;

#if CONSOLE_OUTPUT
#define DUMP_OUTPUT \
    cout<<dump_string.str();
#elif FILE_OUTPUT
#define DUMP_OUTPUT \
    ostringstream file_path;\
    file_path<<"../dump";\
    file_path<<time(NULL)<<".txt";\
    ofstream fout(file_path.str());\
    fout<<dump_string.str();
#endif