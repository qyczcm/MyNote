#include <iostream>
#include <vector>
#include <string>

using namespace std;

void quickSort(vector<int>& nums,int begin,int end){
    if(begin >= end)
        return;
    int low = begin, high = end, key = nums[begin];
    while(low < high){
        while(low < high && nums[high] > key){
            high--;
        }
        if(low < high)
            nums[low++] = nums[high];
        while(low < high && nums[low] < key){
            low++;
        }
        if(low < high)
            nums[high--] = nums[low];
    }
    nums[low] = key;
    quickSort(nums, begin, low - 1);
    quickSort(nums, low + 1, end);
}

int main()
{
    vector<int> nums = {1, 4, 7, 3, 2, 6, 3, 7, 1, 5};
    int len = nums.size();
    quickSort(nums, 0, len - 1);
    for(auto i : nums){
        cout << i << endl;
    }
    return 0;
}
