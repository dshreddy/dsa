#include <bits/stdc++.h>
using namespace std;

class NumArray
{
public:
    vector<int> prefix;

    NumArray(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefix.push_back(sum);
        }
    }
    // 1D array prefix sum
    int sumRange(int left, int right)
    {
        if (left == 0)
            return prefix[right];
        else
            return prefix[right] - prefix[left - 1];
    }
};

class NumMatrix
{
public:
    vector<vector<int> > prefix;

    NumMatrix(vector<vector<int> > &matrix)
    {

        int n = matrix[0].size(), m = matrix.size(), sum;
        prefix.resize(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += matrix[i][j];
                prefix[i + 1][j + 1] = sum + prefix[i][j + 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        row1++;
        col1++;
        row2++;
        col2++;

        int total = prefix[row2][col2], above = prefix[row1 - 1][col2];
        int left = prefix[row2][col1 - 1], left_above = prefix[row1 - 1][col1 - 1];

        return total - left - above + left_above;
    }
};

int main()
{
    // Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    int k = 2;

    int n = nums.size(), sum = 0, ans = 0;
    unordered_map<int, int> count;
    count[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        ans += count[sum - k];
        count[sum]++;
    }

    cout << ans << endl;
    ;
    /*
    https://leetcode.com/problems/range-sum-query-immutable/
    https://leetcode.com/problems/range-sum-query-2d-immutable/
    https://leetcode.com/problems/find-pivot-index/
    https://leetcode.com/problems/product-of-array-except-self/
    https://leetcode.com/problems/subarray-sum-equals-k/
    */
}