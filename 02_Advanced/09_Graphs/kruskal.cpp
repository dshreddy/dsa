#include <bits/stdc++.h>
#define int long long int

using namespace std;

map<int, int> parent;
map<int, int> rank_;

int find(int x)
{

    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
bool Union(int a, int b)
{

    int c = find(a), d = find(b);

    if (c == d)
        return false;

    if (rank_[c] > rank_[d])
        parent[d] = c;
    else if (rank_[d] > rank_[c])
        parent[c] = d;
    else
    {
        parent[d] = c;
        rank_[c]++;
    }
    return true;
}
int kruskal(int n, vector<vector<int> > &edges)
{
    int cost = 0;

    for (int i = 0; i < n; i++)
    {

        parent[i] = i;
        rank_[i] = 0;
    }
    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        edges[i].clear();
        edges[i].push_back(wt);
        edges[i].push_back(u);
        edges[i].push_back(v);
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++)
    {

        vector<int> v1 = edges[i];
        int wt = v1[0], u = v1[1], v = v1[2];
        if (Union(u, v)) cost += wt;
    }
    return cost;
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
https://leetcode.com/problems/min-cost-to-connect-all-points/
https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
*/