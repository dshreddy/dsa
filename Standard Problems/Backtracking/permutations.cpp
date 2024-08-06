#include<bits/stdc++.h>
#define int long long int

using namespace std;

void solve(vector<int>nums) {

    sort(nums.begin(),nums.end());
    int count = 0;

    //works with duplicates too
    do {
        cout<<count+1<<"...."<<"\t";
        for(int i=0; i<nums.size(); i++) cout<<nums[i]<<"\t";
        cout<<endl;
        count++;

    }while(next_permutation(nums.begin(),nums.end()));
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   vector<int>v = {2,1,3,4};
   solve(v);

   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
   /*
https://leetcode.com/problems/permutations/
Solution: https://youtu.be/s7AvT7cGdSo

https://leetcode.com/problems/permutations-ii/
Solution: https://youtu.be/qhBVWf0YafA
*/
}
