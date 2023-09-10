#include <iostream>
#include <vector>

using namespace std;

int countSubsets(vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }

        bool valid = true;
        for (int x = 0; x < subset.size(); x++) {
            for (int y = x + 1; y < subset.size(); y++) {
                if (abs(subset[x] - subset[y]) == k) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                break;
            }
        }

        if (valid) {
            count++;
        }
    }

    return count;
}

int checkAbsoluteDifference(vector<int>& nums, int k) {
    unordered_set<int> diffs; // 使用哈希集合记录已经出现过的绝对差
    for (int num : nums) {
        if (diffs.count(num - k) || diffs.count(k - num)) {
            return 0;
        }
        diffs.insert(abs(num - k));
        diffs.insert(abs(num + k));
    }
    return 1;
}


int main() {
    vector<int> nums = {1,3};
    int k = 2;
    int a = checkAbsoluteDifference(nums,k);
    cout << a << endl;
    ;
    int result = countSubsets(nums, k);
    cout << result << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int countSubsets(vector<int>& nums, int k) {
//     int n = nums.size();

//     // dp[i][j] 表示使用前 i 个数，绝对差为 j 的子集数量
//     vector<unordered_map<int, int>> dp(n + 1);
//     dp[0][0] = 1; // 初始化

//     for (int i = 1; i <= n; i++) {
//         dp[i] = dp[i - 1]; // 继承前一个状态的子集数量
//         for (auto& [diff, count] : dp[i - 1]) {
//             int newDiff = abs(nums[i - 1] - diff);
//             dp[i][newDiff] += count;
//         }
//     }

//     int count = 0;
//     for (auto& [diff, subsetCount] : dp[n]) {
//         if (diff == k) {
//             count += subsetCount;
//         }
//     }

//     return count;
// }

// int main() {
//     vector<int> nums = {2, 4, 6};
//     int k = 2;

//     int result = countSubsets(nums, k);
//     cout << result << endl;

//     return 0;
// }

