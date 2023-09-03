#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findLongestSubstring(const string& str) {
    int maxLength = 0; // 最长子字符串的长度
    int start = 0; // 最长子字符串的起始位置

    for (int i = 0; i < str.length(); i++) {
        int length = 1; // 当前子字符串的长度

        // 探测当前字符与后续字符是否相同
        while (i + length < str.length() && str[i] == str[i + length]) {
            length++;
        }

        // 更新最长子字符串的信息
        if (length > maxLength) {
            maxLength = length;
            start = i;
        }
    }

    return str.substr(start, maxLength);
}

int main() {
    string str="1900:5,5800:45,4998:45";
    string num;
    vector<int> freg;
    int fregnum = 0;
    for(auto c : str){
        if(isdigit(c)){
            num += c;
        }
        else if(c == ':'){
            int temp = stoi(num);
            cout << temp << endl;
            freg.push_back(temp);
            num = "";
        }
    }
    cout<< freg[0];

    return 0;
}
