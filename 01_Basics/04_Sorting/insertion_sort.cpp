#include <bits/stdc++.h>
using namespace std;

using std::vector;

int main()
{
    vector<int> nums = {1,2,-1};

    // insertion sort
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && nums[j] > nums[j + 1])
        {
            swap(nums[j], nums[j + 1]);
            j--;
        }
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << "\t";
    cout << endl;
    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/sort-an-array/
    */
}