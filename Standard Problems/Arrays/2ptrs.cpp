#include<bits/stdc++.h>
using namespace std;

int main()
{
    //  Given a sorted array of integers, return the indices of two elements (in different positions) that sum up to
    //  the target value. Assume there is exactly one solution.
    //  O(n) 

    int arr[] = {1,2,3,4,5,6};
    int n = (sizeof(arr) == 0) ? (0):( sizeof(arr) / sizeof(arr[0]) );
    int target = 5;

    int L = 0, R = n-1;
    while(L<R)
    {
        int sum = arr[L]+arr[R];

        if(sum < target) L++;
        else if(sum > target) R--;
        else break;
    }

    cout<<L<<"\t"<<R<<endl;



    // Given a string of characters, return true if it's a palindrome,
    // return false otherwise: O(n)

    string s = "a";

    L = 0;
    R = s.size()-1;

    bool flag = true;
    while(L<R)
    {
        if(s[L]==s[R])
        {
            L++;
            R--;
        }
        else 
        {
            flag = false;
            break;
        }
    }
    cout<<flag<<endl;

    cout<<(char)('A'+('a'-'A'))<<endl;

    /*
    https://leetcode.com/problems/valid-palindrome/
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
    https://leetcode.com/problems/container-with-most-water/
    https://leetcode.com/problems/trapping-rain-water/
    */
}
