#include <iostream>

using namespace std;
#include "stack_class.h"

int main() {
    Stack s1;
    for (int i=0;i<10;i++)
        s1.push(i+10);
    cout<<s1.size()<<endl;
    for (int i=0;i<s1.size();){
        cout<<s1.pop()<<endl;
    }
    return 0;
}