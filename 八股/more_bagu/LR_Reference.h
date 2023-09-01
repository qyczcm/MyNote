// LR_Reference.h

#ifndef LR_REFERENCE_H
#define LR_REFERENCE_H

/*左值引用（Lvalue Reference）
在这个示例中，lvalueRef 是一个左值引用，它引用了变量 x。通过修改 lvalueRef 的值，实际上也修改了原始的变量 x
*/
void Lvalue_Reference(){
    int x = 5;
    int& lvalueRef = x;  // 使用&符号声明左值引用

    lvalueRef = 10;  // 修改原始变量x的值

    std::cout << "x: " << x << std::endl;  // 输出 x: 10
}

/*右值引用（Rvalue Reference）
在这个示例中，rvalueRef 是一个右值引用，它引用了一个临时的右值 42。右值引用通常用于移动语义和完美转发等高级应用场景中。
*/
void Rvalue_Reference(){
    int x = 5;
    int&& rvalueRef = x;  // 使用&&符号声明右值引用
    

    std::cout << "rvalueRef: " << rvalueRef << std::endl;  // 输出 rvalueRef: 42

}

#endif