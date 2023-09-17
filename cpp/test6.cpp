#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int len = nums.size();
    int maxRes = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int result = nums[i] & nums[j];
            int big = 0;
            cout << "Bitwise AND of " << nums[i] << " and " << nums[j] << " is: " << result << endl;
            //判断能否被2整除
            while (result % 2 == 0 && result != 0)
            {
                result /= 2;
                big += 1;
            }
            maxRes = max(maxRes, big);
        }
    }
    cout << maxRes;

    return 0;
}
