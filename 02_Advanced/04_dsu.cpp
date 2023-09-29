#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:

    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    UnionFind(int n) 
    {
        for (int i = 1; i <= n; i++) 
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find parent of n, with path compression.
    int find(int n) 
    {
        int p = parent[n];
        while (p != parent[p]) 
        {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    // Union by height / rank.
    // Return false if already connected, true otherwise.
    bool uniond(int n1, int n2) 
    {
        int p1 = find(n1), p2 = find(n2);

        if (p1 == p2) return false;

        if (rank[p1] > rank[p2]) parent[p2] = p1;
        else if (rank[p1] < rank[p2]) parent[p1] = p2;
        else 
        {
            parent[p1] = p2;
            rank[p2] += 1;
        }
        return true;
    }
};
int main()
{
    /*
    https://leetcode.com/problems/redundant-connection/
    https://leetcode.com/problems/accounts-merge/
    https://leetcode.com/problems/longest-consecutive-sequence/
    https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
    */
}
