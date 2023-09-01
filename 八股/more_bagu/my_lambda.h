// my_lambda.h

#ifndef MY_LAMBDA_H
#define MY_LAMBDA_H

#include <algorithm>
#include <vector>
#include <iostream>
/*在STL算法中使用Lambda
在这个示例中，使用 Lambda 表达式作为 std::sort() 算法的谓词函数，按照升序对 numbers 进行排序
*/
int Lambda_STL() {
    std::vector<int> numbers = {5, 3, 8, 1, 2, 6, 4};

    // 使用 Lambda 表达式作为谓词函数进行排序
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });

    // 打印排序后的结果
    for (int num : numbers) {
        std::cout << num << " ";
    }
    
    return 0;
}

int Lambda_2() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 使用 Lambda 表达式作为谓词函数进行筛选
    std::vector<int> evenNumbers;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenNumbers),
                 [](int num) {
                     return num % 2 == 0;
                 });

    // 打印筛选后的结果
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }

    return 0;
}





#endif