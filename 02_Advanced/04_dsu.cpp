#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:

    unordered_map<int, int> par_;
    unordered_map<int, int> rank_;

    UnionFind(int n) {
        for (int i = 1; i <= n; i++) {
            par_[i] = i;
            rank_[i] = 0;
        }
    }

    // Find parent of n, with path compression.
    int find(int n) {
        int p = par_[n];
        while (p != par_[p]) {
            par_[p] = par_[par_[p]];
            p = par_[p];
        }
        return p;
    }

    // Union by height / rank.
    // Return false if already connected, true otherwise.
    bool uniond(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank_[p1] > rank_[p2]) {
            par_[p2] = p1;
        } 
        else if (rank_[p1] < rank_[p2]) {
            par_[p1] = p2;
        } 
        else {
            par_[p1] = p2;
            rank_[p2] += 1;
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
