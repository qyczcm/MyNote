#include <iostream>
#include <string>

int main() {
    std::string idCard = "420106202003015148";

    // 提取出生年份
    int birthYear = std::stoi(idCard.substr(6, 4));

    // 提取出生月份
    int birthMonth = std::stoi(idCard.substr(10, 2));

    // 提取出生日期
    int birthDay = std::stoi(idCard.substr(12, 2));

    std::cout << "生日：" << birthYear << "年" << birthMonth << "月" << birthDay << "日" << std::endl;

    return 0;
}
    