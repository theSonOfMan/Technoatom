#include <iostream>

using namespace std;
#include "stack_class.h"

#define creation \
    ostringstream dump_string;\
    dump_string<<"file: "<<__FILE__<<endl;\
    dump_string<<"line: "<<__LINE__<<endl;\
    dump_string<<"function: "<<__FUNCTION__<<endl;

#define output \
    ostringstream file_path;\
    file_path<<"/Users/home/Technoatom/stack_class/dump";\
    file_path<<time(NULL)<<".txt";\
    ofstream fout(file_path.str());\
    fout<<dump_string.str();

int main() {
    //creation
    //output
   // DUMP_CREATION
   // DUMP_OUTPUT
    Stack s;
    s.assert_test();
    return 0;
}