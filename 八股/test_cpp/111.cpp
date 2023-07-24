#include<iostream>        //动态规划
#include<string>
#include<vector>
using namespace  std;
int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    vector<int> v;
    int count = 0;
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            t += s[i];
        else {
            if (t.size() > 0) {
                v.push_back(stoi(t, 0, 10));
                count++;
                t = "";
            }
        }
    }
}