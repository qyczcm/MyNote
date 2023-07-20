#include <iostream>
using namespace std;

int main() {
    int a; // 在栈中分配
    int b;
    int *c = new int; // 在堆中分配
    int *d = new int;
    cout << "a: " << &a << endl;
    cout << "b: " << &b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    delete c;
    delete d;
    return 0;
}
