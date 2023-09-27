#include<bits/stdc++.h>
#define int long long int

using namespace std;

// Given a list of edges of a connected undirected graph,
// with nodes numbered from 1 to n,
// return a list edges making up the minimum spanning tree.
vector<pair<int, int> > mst(vector<vector<int> >& edges, int n) {

    //Making an undirected graph from given edges
    unordered_map<int, vector<pair<int, int> > > adj;
    for (vector<int> edge : edges) {

        int n1 = edge[0], n2 = edge[1], weight = edge[2];
        adj[n1].push_back(make_pair(n2, weight));
        adj[n2].push_back(make_pair(n1, weight));
    }

    // Initialize the heap by choosing a single node
    // (in this case 1) and pushing all its neighbors.
    priority_queue<tuple<int,int,int>, vector<tuple<int,int, int>>, greater<tuple<int, int, int> > > minHeap; 

    for (pair<int, int> neighbor : adj[1]) {
        int node = neighbor.first, weight = neighbor.second;
        minHeap.push({weight, 1, node});
    }
    
    vector<pair<int, int>> mst;
    unordered_set<int> visit;
    visit.insert(1);

    while (visit.size() < n) {

        tuple<int, int, int> cur = minHeap.top();
        minHeap.pop();

        int w1 = get<0>(cur), n1 = get<1>(cur), n2 = get<2>(cur);

        if (visit.count(n2) > 0) continue;

        mst.push_back({n1, n2});
        visit.insert(n2);
        for (pair<int, int> p : adj[n2]) {

            int neighbor = p.first, weight = p.second;
            if (visit.count(neighbor) == 0) minHeap.push({weight, n2, neighbor});
        }
    }
    
    return mst;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}
/*
https://leetcode.com/problems/min-cost-to-connect-all-points/
https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
*/