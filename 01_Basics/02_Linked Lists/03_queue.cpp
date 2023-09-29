#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val_;
    ListNode* next = nullptr;

    inline ListNode() {}
    inline ListNode(int val) { val_ = val; }
};

class Queue {
public:
    ListNode* left = nullptr;
    ListNode* right = nullptr;

    Queue() {}

    void enqueue(int val) 
    {
        ListNode* newNode = new ListNode(val);

        if (right != nullptr) 
        {
            right->next = newNode;
            right = right->next;
        } 
        else left = right = newNode;
    }

    int dequeue() 
    {
        // Queue is empty
        if (left == nullptr) return -1; 

        int val = left->val_;
        left = left->next;
        return val;
    }

    void print() 
    {
        ListNode* curr = left;
        while (curr != nullptr) 
        {
            cout << curr->val_ << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
    https://leetcode.com/problems/implement-stack-using-queues/
    */
}
