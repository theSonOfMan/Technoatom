#include <iostream>

using namespace std;
#include "stack_class.h"

int main() {
   Stack s;
    s.push(10);
    cout<<s.top()<<endl;
    cout<<*(s.top());
    return 0;
}