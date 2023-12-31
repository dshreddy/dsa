#include <bits/stdc++.h>
#define int long long int

using namespace std;

string longestPalindrome(string s)
{
   string lps;
   int maxl = INT_MIN;

   for (int i = 0; i < s.size(); i++)
   {

      int l = i, r = i;

      // lps of odd length
      while (l >= 0 && r < s.size() && s[l] == s[r])
      {

         if (r - l + 1 > maxl)
         {

            maxl = max(maxl, r - l + 1);
            lps = s.substr(l, maxl);
         }
         l--;
         r++;
      }

      l = i, r = i + 1;
      // lps of even length
      while (l >= 0 && r < s.size() && s[l] == s[r])
      {

         if (r - l + 1 > maxl)
         {

            maxl = max(maxl, r - l + 1);
            lps = s.substr(l, maxl);
         }
         l--;
         r++;
      }
   }
   return lps;
}

signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cout << (float)clock() / CLOCKS_PER_SEC << endl;
   return 0;
}
/*
https://leetcode.com/problems/longest-palindromic-substring/
https://leetcode.com/problems/palindromic-substrings/
https://leetcode.com/problems/longest-palindromic-subsequence/
*/