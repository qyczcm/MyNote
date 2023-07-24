#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyClass {
public:
    int n;
    void method();
};

void change5(MyClass &mc) {
    // ...
}

int* createDynamicInt() {
    int* ptr = new int(5);
    return ptr;
}

void deleteDynamicInt(int* ptr) {
    delete ptr;
}

void incrementByReference(int& num) {
    num++;
}

// int main()
// {
//     //当需要返回函数内局部变量的地址时，使用指针
//     int* dynamic = createDynamicInt();
//     deleteDynamicInt(dynamic);

//     //当对栈空间大小比较敏或者需要避免创建临时量时，使用引用
//     int num = 5;
//     incrementByReference(num);
//     //在函数change5()中，参数myobj是MyClass类的一个引用。这样，函数change5()就可以直接访问myobj所引用的对象，
//     //而不需要进行复制。这种方式可以避免复制大量数据，提高程序效率。
//     MyClass myobj;
//     change5(myobj);

//     return 0;
// }
