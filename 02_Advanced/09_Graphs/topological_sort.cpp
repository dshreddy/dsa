#include<bits/stdc++.h>
#define int long long int

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) 
    {
        map<int,int>indeg;
        vector<vector<int> >G(numCourses);

        for(auto vec: prerequisites)  
        {
            G[vec[1]].push_back(vec[0]);
            indeg[vec[0]]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++) if(indeg[i]==0) q.push(i);

        int flag = numCourses - q.size();

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            for(int nb: G[i]) 
            {
                indeg[nb]--;
                if(indeg[nb]==0)
                {
                    q.push(nb);
                    flag--;
                }
            }
        }

        return flag==0;
    }
};

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}

/*
https://leetcode.com/problems/course-schedule/
https://leetcode.com/problems/course-schedule-ii/
https://leetcode.com/problems/course-schedule-iv/
https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
https://leetcode.com/problems/alien-dictionary/
*/