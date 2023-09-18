#include <iostream>
#include <chrono>

// 计算从 start 到 end 之间间隔的天数
int daysBetween(const std::chrono::system_clock::time_point& start, 
const std::chrono::system_clock::time_point& end)
{
    auto duration = std::chrono::duration_cast<std::chrono::hours>(end - start);
    return static_cast<int>(duration.count() / 24);
}

int main()
{
    // 获取当前日期
    auto now = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(now);
    auto tm = *std::localtime(&t);
      // 修改 tm 的值
    tm.tm_year = 2020;  // 年份减去 1900
    tm.tm_mon = 2;         // 月份需要减 1，因为月份从 0 开始
    tm.tm_mday = 11;           // 设置日期为 17

    // 转换为时间戳
    auto new_time = std::mktime(&tm);

    // 转换回 std::chrono::time_point
    auto new_now = std::chrono::system_clock::from_time_t(new_time);

    // 输出修改后的时间点
    // std::cout << new_now << std::endl;
    std::string idCard = "420106202003015148";


    // 提取出生年份
    int birthYear = std::stoi(idCard.substr(6, 4));

    // 提取出生月份
    int birthMonth = std::stoi(idCard.substr(10, 2));

    // 提取出生日期
    int birthDay = std::stoi(idCard.substr(12, 2));

    // 构造生日日期时间戳
    std::tm birthday_tm = {0};
    birthday_tm.tm_year = birthYear - 1900;
    birthday_tm.tm_mon = birthMonth - 1;
    birthday_tm.tm_mday = birthDay;
    auto birthday_time = std::mktime(&birthday_tm);
    auto birthday = std::chrono::system_clock::from_time_t(birthday_time);

    // 计算与生日日期间隔的天数
    bool is_after_birthday = false;
    if (now > birthday) {
        // 已经过了生日，计算下一年的生日日期
        birthday_tm.tm_year = tm.tm_year + 1;
        birthday_time = std::mktime(&birthday_tm);
        birthday = std::chrono::system_clock::from_time_t(birthday_time);
    }
    std::cout << "距离下次生日还有 " << daysBetween(new_now, birthday) << " 天" << std::endl;

    return 0;
}
