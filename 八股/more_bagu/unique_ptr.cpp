#include <memory>
#include <iostream>


// int main(int argc, char const *argv[])
// {
//     /* code */
//     // 创建一个 unique_ptr，指向一个动态分配的 int 对象
//     std::unique_ptr<int> p1(new int(42));

//     // 无法创建另一个 unique_ptr，因为一份动态内存不能被多个 unique_ptr 共享
//     // std::unique_ptr<int> p2 = p1; // 编译错误

//     // 通过重载的箭头运算符访问动态分配的对象
//     std::cout << "*p1 = " << *p1 << std::endl; // 输出 42
//     return 0;
// }
