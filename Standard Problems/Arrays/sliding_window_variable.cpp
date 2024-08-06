#include<bits/stdc++.h>
using namespace std;

int main()
{
    int target = 7;
    int n = 6;
    int nums[6] = {2,3,1,2,4,3};

    // Find length of minimum size subarray where the sum is 
    // greater than or equal to the target: O(n)

    int l =0, sum = 0, min_len = INT_MAX;
    for(int r=0; r<n; r++)
    {
        sum += nums[r];

        while(sum >= target && l<=r)
        {
            min_len = fmin(min_len, r-l+1);
            sum -= nums[l];
            l++;
        }
    }
    cout<<min_len<<endl;

    //longest subarray with same value in each position
    //O(n)
    
    int N = 6;
    int b[] = {4,2,2,3,3,3};

    int L = 0, maxl = INT_MIN;
    for(int r=0; r<N; r++)
    {
        if(b[L]!=b[r]) L = r;
        maxl = fmax(maxl, r-L+1);
    }
    cout<<maxl<<endl;

    /*
    https://leetcode.com/problems/minimum-size-subarray-sum/
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
    https://leetcode.com/problems/longest-repeating-character-replacement/
    */
}
