#include <iostream>
#include <chrono>
#include <string>

// 计算从 start 到 end 之间间隔的天数
int daysBetween(const std::chrono::system_clock::time_point& start,
                const std::chrono::system_clock::time_point& end)
{
    auto duration = std::chrono::duration_cast<std::chrono::hours>(end - start);
    return static_cast<int>(duration.count() / 24);
}

int main()
{
    // 提取身份证输入
    std::string idCard;
    std::cout << "请输入身份证号码：";
    std::cin >> idCard;

    // 提取生日信息
    int year, month, day;

    if (idCard.length() == 18) {
        year = std::stoi(idCard.substr(6, 4));
        month = std::stoi(idCard.substr(10, 2));
        day = std::stoi(idCard.substr(12, 2));
    }
    else if (idCard.length() == 15) {
        year = 1900 + std::stoi(idCard.substr(6, 2));
        month = std::stoi(idCard.substr(8, 2));
        day = std::stoi(idCard.substr(10, 2));
    }
    else {
        std::cout << "无效的身份证号码" << std::endl;
        return 0;
    }

    // 构造生日日期时间戳
    std::tm birthday_tm = {0};
    birthday_tm.tm_year = year - 1900;
    birthday_tm.tm_mon = month - 1;
    birthday_tm.tm_mday = day;
    auto birthday_time = std::mktime(&birthday_tm);
    auto birthday = std::chrono::system_clock::from_time_t(birthday_time);

    // 提取用户输入的当前年月日
    int currentYear, currentMonth, currentDay;
    std::cout << "请输入当前的年份：";
    std::cin >> currentYear;
    std::cout << "请输入当前的月份：";
    std::cin >> currentMonth;
    std::cout << "请输入当前的日期：";
    std::cin >> currentDay;

    // 构造当前日期时间戳
    std::tm current_tm = {0};
    current_tm.tm_year = currentYear - 1900;
    current_tm.tm_mon = currentMonth - 1;
    current_tm.tm_mday = currentDay;
    auto current_time = std::mktime(&current_tm);
    auto now = std::chrono::system_clock::from_time_t(current_time);

    // 计算与生日日期间隔的天数
    bool is_after_birthday = false;
    if (now > birthday) {
        // 已经过了生日，计算下一年的生日日期
        auto next_year = year + 1;
        birthday_tm.tm_year = next_year - 1900;
        birthday_time = std::mktime(&birthday_tm);
        birthday = std::chrono::system_clock::from_time_t(birthday_time);
    }
    std::cout << "距离下次生日还有 " << daysBetween(now, birthday) << " 天" << std::endl;

    return 0;
}
