#include <iostream>

int main() {
    int num = 10;
  
    // 常量指针
    const int* ptr1 = &num;    // 指向常量的指针
    // *ptr1 = 20;             // 错误，不能通过常量指针修改所指向的对象的值
    num = 20;                 // 可以直接修改变量的值
    ptr1 = nullptr;           // 可以修改指针的指向
    
    // 指针常量
    int* const ptr2 = &num;    // 常量指针
    *ptr2 = 30;                // 可以通过指针修改所指向的对象的值
    // ptr2 = nullptr;        // 错误，不能修改指针本身的值（即指针的指向）
    
    std::cout << "num: " << num << std::endl;
    std::cout << "*ptr1: " << *ptr1 << std::endl;
    std::cout << "*ptr2: " << *ptr2 << std::endl;

    return 0;
}
