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
    sort(nums.begin(), nums.end());
    int maxRes = nums[n - 1]; // 假设数组中的第一个数为最大的数

    int getmax = 0;
    for (int i = 0; i < n-1; i++) {

        int Res = maxRes & nums[i]; // 依次按位与运算
        cout << Res << endl;
        if(Res != 0 && Res % 2 == 0){
            getmax = max(getmax, Res);
        }
        
    }

    int big = 0;
    while(getmax % 2 == 0 && getmax != 0)
    {
        getmax /= 2;
        big += 1;
    }
    cout << big;

    return 0;
}
