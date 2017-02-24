#include <iostream>

using namespace std;
#include "stack_class.h"

int main() {
    Stack s1;
    s1.push(10);
    s1.push(11);
    s1.push(12);
    while (!s1.empty()){
        cout<<s1.pop()<< ' ';
    }
    return 0;
}