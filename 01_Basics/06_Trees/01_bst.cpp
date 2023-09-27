#include<bits/stdc++.h>
using namespace std;

/*
Binary Search Tree is a node-based binary tree data structure which has the following properties:
The left subtree of a node contains only nodes with keys lesser than the root node’s key.
The right subtree of a node contains only nodes with keys greater than the root node’s key.
The left and right subtree each must also be a binary search tree.

Sets & Maps can be implemented using BST's
*/

class Node {
    public:
        int val;
        Node* left = nullptr;
        Node* right = nullptr;

        Node() {}
        Node(int x) { val = x; }
};

//O(log n), with each decision the tree was made half
bool search(Node* root, int target) {

    if (root==NULL) return false;
    if (target > root->val) return search(root->right, target);
    else if (target < root->val) return search(root->left, target);
    else return true;
}

int main()
{
    /*
              8
              /\
            3   10
           /\     \
          1  6    14
    */

    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    cout<<search(root,6)<<endl;

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/search-in-a-binary-search-tree/
    https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
    */
}