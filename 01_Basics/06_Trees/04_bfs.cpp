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
//O(size of tree)
void bfs(Node* root) {

    queue<Node*> queue;

    if (root) queue.push(root);
    
    int level = 0;
    while (queue.size() > 0) {

        cout << "level: " << level << endl;
        int length = queue.size();

        for (int i = 0; i < length; i++) {

            Node* curr = queue.front();
            queue.pop();

            cout << curr->val <<"\t";

            if (curr->left) queue.push(curr->left);
            if (curr->right) queue.push(curr->right);
        }
        level++;
        cout << endl;
    }
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

    bfs(root);

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/binary-tree-level-order-traversal/
    https://leetcode.com/problems/binary-tree-right-side-view/
    */
}