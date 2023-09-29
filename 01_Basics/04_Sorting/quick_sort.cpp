#include <bits/stdc++.h>
using namespace std;

//O(log n)
void quickSort(vector<int>& arr, int s, int e) {

    if (e <= s) return ;

    int pivot = arr[e];
    int left = s; // pointer for left side

    // Partition: elements smaller than pivot on the left side.
    for (int i = s; i < e; i++) {
        if (arr[i] < pivot) {
            int tmp = arr[left];
            arr[left] = arr[i];
            arr[i] = tmp;
            left++;
        }
    }

    // Move pivot in-between left & right sides
    arr[e] = arr[left];
    arr[left] = pivot;
    
    // Quick sort left side
    quickSort(arr, s, left - 1);
    // Quick sort right side
    quickSort(arr, left + 1, e);
}

int main()
{
    vector<int>nums = {1,2,-1};

    //tita(n*logn)
    quickSort(nums,0,nums.size()-1);

    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<"\t";
    cout<<endl;
    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/sort-an-array/
    https://leetcode.com/problems/kth-largest-element-in-an-array/
    */
}