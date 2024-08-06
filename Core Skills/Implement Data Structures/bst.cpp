#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:

    int val;
    TreeNode *left = nullptr, *right = nullptr;

    TreeNode() {}

    TreeNode(int x) {
        val = x;
    }

    TreeNode(TreeNode *l, TreeNode *r) {
        left = l;
        right = r;
    }

    TreeNode(int x, TreeNode *l, TreeNode *r) {
        val = x;
        left = l;
        right = r;
    }
};

class BST {
public: 

    TreeNode * root = nullptr;

    BST() {}

    TreeNode* search(TreeNode * root, int x) {
        if(!root) return root;

        if(x < root->val) return search(root->left, x);
        else if(x > root->val) return search(root->right, x);
        else return root;
    }

    TreeNode* insert(TreeNode * root, int x) {

        if(root == nullptr) {
            root = new TreeNode(x);
            return root;
        }

        if(x > root->val) root->right = insert(root->right, x);
        else if(x < root->val) root->left = insert(root->left, x);

        return root;
    }

    // Assuming root is not empty
    int min(TreeNode * root) {
        while(root->left) root = root->left;
        return root->val;
    }

    TreeNode* erase(TreeNode * root, int x) {
        if(!root) return root;

        if(x > root->val) root->right = erase(root->right, x);
        else if(x < root->val) root->left = erase(root->left, x);
        else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            int t = min(root->right);
            root->val = t;
            root->right = erase(root->right, t);
        }
        return root;
    }

    void print() {

        // Level order traversal

        queue<TreeNode*>q;
        if(root) q.push(root);

        while(!q.empty()){
            
            int l = q.size();

            for(int i=0; i<l; i++) {
                TreeNode *u = q.front();
                q.pop();
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
                cout<<u->val<<"\t";
            }
            cout<<"\n";
        }
    }
};

int main() {

    BST t;
    t.root = t.insert(t.root, 3);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 1);
    t.root = t.insert(t.root, 6);
    t.root = t.insert(t.root, 4);
    t.print();
}