#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>nums = {-1,2,3};

    // Brute Force: O(n^2)
    int max_Sum = nums[0];
    for (int i = 0; i < nums.size(); i++) 
    {
        int curSum = 0;
        for (int j = i; j < nums.size(); j++) 
        {
            curSum += nums[j];
            max_Sum = max(max_Sum, curSum);
        }
    }
    cout<<max_Sum<<endl;

    // Return the left and right index of the max subarray sum,
    // assuming there's exactly one result (no ties).
    // Sliding window variation of Kadane's: O(n)
    int maxSum = nums[0];
    int curSum = 0, temp = 0;
    int maxL = 0, maxR = 0;

    for (int R = 0; R < nums.size(); R++) 
    {
        curSum += nums[R];
        if (curSum > maxSum) 
        {
            maxSum = curSum;
            maxL = temp; 
            maxR = R;     
        } 
        if (curSum < 0) 
        {
            curSum = 0;
            temp = R+1;
        }
    }    
    cout<<maxL<<" "<<maxR<<endl;

    /*
    https://leetcode.com/problems/maximum-subarray/
    https://leetcode.com/problems/maximum-sum-circular-subarray/
    https://leetcode.com/problems/longest-turbulent-subarray/
    */

    return 0;
}
