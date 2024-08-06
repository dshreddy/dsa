#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

    TreeNode() {}
    TreeNode(int x) : val(x) {}
};

// Time and space: O(n)
void inorder(TreeNode* root) {

    cout<<"inorder :\n";
    stack<TreeNode*> stack;
    TreeNode * curr = root;

    while (curr || !stack.empty()) {

        if (curr) 
        {
            stack.push(curr);
            curr = curr->left;
        } 
        else 
        {
            curr = stack.top();
            stack.pop();
            cout << curr->val << "\t";
            curr = curr->right;
        }
    }
    cout<<endl;
}

// Time and space: O(n)
void preorder(TreeNode* root) {

    cout<<"preorder :\n";
    stack<TreeNode*> stack;
    TreeNode* curr = root;

    while (curr || !stack.empty()) {

        if (curr) 
        {
            cout << curr->val << "\t";
            if (curr->right) stack.push(curr->right);
            curr = curr->left;
        } 
        else 
        {
            curr = stack.top();
            stack.pop();
        }
    }
    cout<<endl;
}

// Time and space: O(n)
void postorder(TreeNode* root) {

    cout<<"postorder :\n";
    stack<TreeNode*> stack;
    stack.push(root);
    vector<bool> visit;
    visit.push_back(false);

    while (!stack.empty()) 
    {
        TreeNode* curr = stack.top();
        stack.pop();
        bool visited = visit.back();
        visit.pop_back();

        if (curr) 
        {
            if (visited) cout << curr->val << "\t";
            else 
            {
                stack.push(curr);
                visit.push_back(true);

                stack.push(curr->right);
                visit.push_back(false);

                stack.push(curr->left);
                visit.push_back(false);
            }
        }
    }
    cout<<endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    inorder(root);
    preorder(root);
    postorder(root);

    /*
    https://leetcode.com/problems/binary-search-tree-iterator/
    https://leetcode.com/problems/binary-tree-preorder-traversal/
    https://leetcode.com/problems/binary-tree-postorder-traversal/
    */
}
