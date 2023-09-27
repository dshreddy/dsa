#include<bits/stdc++.h>
using namespace std;

//O(log n)
int binarySearch(vector<int> arr, int target) {
    int L = 0, R = arr.size();

    while (L <= R) {
        int mid = (L + R) / 2;

        if (target > arr[mid]) {
            L = mid + 1;
        } else if (target < arr[mid]) {
            R = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);

    cout<<binarySearch(nums,1)<<endl;
}
