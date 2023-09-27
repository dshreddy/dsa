#include<bits/stdc++.h>
using namespace std;

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

// Insert a new node and return the root of the tree.
//O(log n)
Node* insert(Node* root, int val) 
{
    if (root==NULL) return new Node(val);

    if (val > root->val) root->right = insert(root->right, val);
    else if (val < root->val) root->left = insert(root->left, val);
    return root;
}

// Return the minimum value node of the BST.
//O(h)
Node* minValueNode(Node* root) {
    Node* curr = root;
    while (curr && curr->left) curr = curr->left;
    return curr;
}

// Remove a node and return the root of the tree.
//O(log n)
Node* remove(Node* root, int val) {
    if (!root) return new Node(val);

    if (val > root->val) root->right = remove(root->right, val);
    else if (val < root->val) root->left = remove(root->left, val);
    else {

        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        else {

            Node* minNode = minValueNode(root->right);
            root->val = minNode->val;
            root->right = remove(root->right, minNode->val);
        }
    }
    return root;
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
    root = insert(root,3);
    root = insert(root,10);
    root = insert(root,1);
    root = insert(root,6);
    root = insert(root,14);

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/insert-into-a-binary-search-tree/
    https://leetcode.com/problems/delete-node-in-a-bst/
    */
}
