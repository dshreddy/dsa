#include <bits/stdc++.h>
using namespace std;

//O(n)
void bucketSort(vector<int>& arr) {

    // Assuming arr only contains 0, 1 or 2
    int counts[] = {0, 0, 0};

    for (int n: arr) counts[n]++;

    int i = 0;
    for (int n = 0; n < 3; n++) for (int j = 0; j < counts[n]; j++) arr[i++] = n;
}

int main()
{
    vector<int>arr = {0,2,1,0};

    bucketSort(arr);

    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<"\t";
    cout<<endl;
    
    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/sort-colors/
    */
}