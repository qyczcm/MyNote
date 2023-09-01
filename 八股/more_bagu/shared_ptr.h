// shared_ptr.h

#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <memory>
#include <iostream>

void my_shared_ptr() {
    // 创建一个 shared_ptr，指向一个动态分配的 int 对象
    std::shared_ptr<int> p1(new int(42));

    // 创建另一个 shared_ptr，与 p1 共享同一个对象
    std::shared_ptr<int> p2 = p1;

    // 通过 use_count 函数查看指向同一对象的智能指针数量
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl; // 输出 2
    std::cout << "p2.use_count() = " << p2.use_count() << std::endl; // 输出 2

    // 通过重载的箭头运算符访问动态分配的对象
    std::cout << "*p1 = " << *p1 << std::endl; // 输出 42
    std::cout << "*p2 = " << *p2 << std::endl; // 输出 42
}

#endif
