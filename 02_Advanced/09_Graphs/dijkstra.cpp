#include<bits/stdc++.h>
#define int long long int
using namespace std;

//Only valid for graphs with positive weights
unordered_map<int, int> shortestPath(vector<vector<int> >& edges, int n, int src) {

    unordered_map<int, vector<pair<int, int> > > adj;

    for (vector<int> edge : edges) {

        // s = source, d = destination, w = weight
        int s = edge[0], d = edge[1], w = edge[2];
        adj[s].push_back(make_pair(d, w));
    }
    unordered_map<int, int> shortest;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > minHeap; 
    minHeap.push({0, src});

    while (!minHeap.empty()) {

        pair<int, int> p = minHeap.top();
        minHeap.pop();

        int w1 = p.first, n1 = p.second;

        //once the sd is assigned we don't visit again
        if (shortest.count(n1) > 0) continue;
        
        shortest[n1] = w1;
        for (pair<int, int> p : adj[n1]) {

            int n2 = p.first, w2 = p.second;
            if (shortest.count(n2) == 0) minHeap.push({w1 + w2, n2});
        }
    }
    return shortest;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   int v=3,e = 1;
   vector<vector<int> >edges;
   vector<int>t;

   //edge 1
   t.push_back(1);
   t.push_back(2);
   t.push_back(3);
   edges.push_back(t);

   shortestPath(edges,v,0);

   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;

   /*
    https://leetcode.com/problems/network-delay-time/
    https://leetcode.com/problems/swim-in-rising-water/
    https://leetcode.com/problems/path-with-maximum-probability/
    */
}
