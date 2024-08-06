#include <bits/stdc++.h>
using namespace std;

class SegTreeNode {
public:
    int val, l, r;
    SegTreeNode *left, *right;
    SegTreeNode(int x, int y, int z) : val(x), l(y), r(z), left(nullptr), right(nullptr) {}
};

class SegTree {
private: 
    SegTreeNode *root;

    SegTreeNode* build(vector<int> &v, int l, int r) {
        if (l == r) return new SegTreeNode(v[l], l, r);
        else {
            int m = (l + r) / 2;
            SegTreeNode *node = new SegTreeNode(0, l, r);
            node->left = build(v, l, m);
            node->right = build(v, m + 1, r);
            node->val = node->left->val + node->right->val;
            return node;
        }
    }

    void update(SegTreeNode *node, int val, int i) {
        int l = node->l, r = node->r;
        if (l == r) node->val = val;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(node->left, val, i);
            else update(node->right, val, i);
            node->val = node->left->val + node->right->val;
        }
    }

    int query(SegTreeNode *node, int x, int y) {
        int l = node->l, r = node->r;
        if (x == l && r == y) return node->val;
        else {
            int m = (l + r) / 2;
            if (y <= m) return query(node->left, x, y);
            else if (x > m) return query(node->right, x, y);
            else return query(node->left, x, m) + query(node->right, m + 1, y);
        }
    }

public: 
    SegTree(vector<int> &v) { 
        root = build(v, 0, v.size() - 1); 
    }

    void update(int val, int i) {
        update(root, val, i);
    }

    int query(int l, int r) {
        return query(root, l, r);
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    SegTree segTree(v);

    cout << segTree.query(0, 2) << endl;  // Output: 6
    segTree.update(10, 1);
    cout << segTree.query(0, 2) << endl;  // Output: 14
}
