#include <iostream>
#include <cassert>
using namespace std;
#include "stack_class.h"

int main() {
    Stack s1;
    s1.push(10);
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;

    return 0;
}