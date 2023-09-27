#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Check if array contains a pair of duplicate values,
    // where the two duplicates are no farther than k positions from 
    // eachother (i.e. arr[i] == arr[j] and abs(i - j) + 1 <= k).

    int arr [] = {1,2,3,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    //Key Idea O(n)
    int l = 0;
    for(int r=k-1; r<n; r++)
    {
        for(int i=l; i<=r; i++) cout<<arr[i]<<"\t";
        cout<<endl;
        l++;
    }
    
    /*
    https://leetcode.com/problems/contains-duplicate-ii/
    https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
    */
}