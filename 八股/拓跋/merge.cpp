#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mergeSortCore(vector<int>& data, vector<int>& temp, int low, int high){
    if(low >= high)
        return;
    int len = high - low;
    int mid = low + len / 2;
    int start1 = low, end1 = mid, start2 = mid + 1, end2 = high;
    mergeSortCore(data, temp, start1, end1);
    mergeSortCore(data, temp, start2, end2);
    int index = low;
    while(start1 <= end1 && start2 <= end2){
        temp[index++] = data[start1] < data[start2] ? data[start1++] : data[start2++];
    }
    while(start1 <= end1){
        temp[index++] = data[start1++];
    }
    while(start2 <= end2){
        temp[index++] = data[start2++];
    }
    for (index = low; index <= high; index++){
        data[index] = temp[index];
    }
}

int main()
{
    vector<int> data = {3, 5, 1, 7, 4, 8, 6, 7, 0};
    int len = data.size();
    vector<int> temp(len,0);
    mergeSortCore(data, temp, 0, len - 1);
    for(auto i : data){
        cout << i << endl;
    }

    return 0;
}
