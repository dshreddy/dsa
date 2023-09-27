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

//O(size of Tree)
void inorder(Node* root) {

    if (root==NULL) return;
    inorder(root->left);
    cout << root->val << "\t";
    inorder(root->right);
}

void preorder(Node* root) {

    if (root==NULL) return;
    cout << root->val << "\t";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {

    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << "\t";
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

    inorder(root);
    cout<<endl;

    preorder(root);
    cout<<endl;

    postorder(root);
    cout<<endl;

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/binary-tree-inorder-traversal/
    https://leetcode.com/problems/kth-smallest-element-in-a-bst/
    https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    */
}