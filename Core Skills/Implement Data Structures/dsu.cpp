#include<bits/stdc++.h>
using namespace std;

class DSU{
private:
    int n;
    vector<int>parent;
    vector<int>rank;

public:

    DSU(int x) {
        n = x;
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int p) {
        if(p != parent[p]) parent[p] = find(parent[p]);
        return parent[p];
    }

    bool Union(int p, int q) {
        int a = find(p), b = find(q);
        if(a == b) return false;

        if(rank[a]<rank[b]) {
            parent[a] = b;
            rank[b] += rank[a];
        } else {
            parent[b] = a;
            rank[a] += rank[b];
        }

        return true;
    }
};

int main() {
    DSU dsu(5);  // Initialize DSU with 5 elements
    dsu.Union(0, 1);
    dsu.Union(1, 2);
    cout << dsu.find(0) << endl;  // Output should be the root of the set containing 0
    cout << dsu.find(2) << endl;  // Output should be the same as above since 0 and 2 are connected
}