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

using std::cin;
using std::cout;
using std::ostringstream;
using std::endl;
using std::ofstream;
using std::string;

// FIXME: Идея спрашивать у пользоваьеля на каждом шагу, куда писать логи прикольная, но не юзабельная.
// Ассертов много. Очень много. Еще я бы посоветовал тебе сделать макрос-логгер и вызывать ее из ассерта, когда
// что-то пошло не так.
#define ASSERT_OK(p) \
do{\
    if (!(p)) {\
        DUMP_CREATION\
        cout<<endl<<"Critical failure, program is going to close."<<endl;\
        cout<<"Type '1' to print the logs in the console."<<endl\
        <<"Type '2' to print the logs in the file"<<endl;\
        int user_response;\
        cin>>user_response;\
        if (user_response == 1) {CONSOLE_OUTPUT}\
        if (user_response == 2) {FILE_OUTPUT}\
        exit(1);\
    }\
} while (false);

// FIXME: добавь в название функции gen
string dump_file_name() {
    ostringstream file_path;
    file_path<<"../dump";
    file_path<<time(NULL)<<".txt";
    return file_path.str();
}

#define DUMP_CREATION \
    ostringstream dump_string;\
    dump_string<<"file: "<<__FILE__<<endl;\
    dump_string<<"line: "<<__LINE__<<endl;\
    dump_string<<"function: "<<__FUNCTION__<<endl;\
    dump_string<<dump()<<endl;

#define CONSOLE_OUTPUT \
    cout<<dump_string.str();

// FIXME: Открывать-закрывать файл каждый раз - долго. Сделай глобальный лог файл и пиши туда.
#define FILE_OUTPUT \
    string path = dump_file_name();\
    ofstream fout(path);\
    fout<<dump_string.str();\
    cout<<"logs were put in "<<path;\ // FIXME: А вот эта строка не нужна совсем. Вдруг нету консоли, ибо приложение запущено через сеть на другой машине?!
    fout.close();
