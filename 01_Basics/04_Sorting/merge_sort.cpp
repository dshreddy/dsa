#include <bits/stdc++.h>
using namespace std;

void merge(int p, int mid, int q, vector<int> &nums)
{
    vector<int> v;
    int i = p, j = mid + 1;

    while (i <= mid && j <= q)
    {
        if (nums[i] < nums[j])
        {
            v.push_back(nums[i]);
            i++;
        }
        else
        {
            v.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        v.push_back(nums[i]);
        i++;
    }
    while (j <= q)
    {
        v.push_back(nums[j]);
        j++;
    }

    for (int i = p; i <= q; i++) nums[i] = v[i - p];
}

void merge_sort(int p, int q, vector<int> &nums)
{
    if (p < q)
    {
        int mid = (p + q) / 2;

        merge_sort(p, mid, nums);
        merge_sort(mid + 1, q, nums);
        merge(p, mid, q, nums);
    }
}

int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);

    //tita(n*logn)
    merge_sort(0, nums.size()-1, nums);

    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<"\t";
    cout<<endl;

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/sort-an-array/
    https://leetcode.com/problems/merge-k-sorted-lists/
    */
    return 0;
}