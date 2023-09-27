#include<bits/stdc++.h>
using namespace std;

/*
    Main difference between arrays & linked lists are
    Arrays have fixed size, linked list size is not bounded
    In arrays random access of elements at some index is possible while it isn't possible in list
    In arrays all elements are stored in contigous block, while in linked list that isn't the case
*/

class Node {
public :
    int val;
    Node * next = NULL;

    inline Node() {}

    inline Node(int x) {val = x;}

    inline Node(int x, Node *n) {val = x; next = n;}
};
//O(n)
void Print(Node* head)
{
    while(head)
    {
        cout<<head->val<<"\t";
        head = head->next;
    }
    cout<<endl;
}
//O(n)
Node* InsertAt(int i, int val, Node *head) 
{
    Node *new_node = new Node(val);

    if(head == NULL) head = new_node;
    else {

        if(i==0) 
        {
            new_node->next = head;
            head = new_node;
        }
        else 
        {
            Node *p = head,*q = head->next;
            for(int j=0; j<i-1; j++)
            {
                p = p->next;
                if(q) q = q->next; 
            }
            p->next = new_node;
            new_node->next = q;
        }
    }

    return head;
}
//O(n)
Node* RemoveAt(int i, Node *head) 
{
    if(head == NULL) return head;
    else {

        if(i==0) head = head->next;
        else 
        {
            Node *p = head,*q = head->next;
            for(int j=0; j<i-1; j++)
            {
                p = p->next;
                if(q) q = q->next; 
            }
            p->next = q->next;
        }
    }
    return head;
}  

int main() 
{
    Node* head = NULL;

    //inserting at end
    for(int i=0; i<10; i++) head = InsertAt(i,i+1,head);

    //inserting at start
    head = InsertAt(0,0,head);

    //inserting at Middle
    head = InsertAt(1,11,head);

    Print(head);

    //Removing at middle
    head = RemoveAt(1,head);

    //Removing at end
    head = RemoveAt(10,head);

   //Removing at start
    head = RemoveAt(0,head);

    Print(head);

    return 0;

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/reverse-linked-list/
    https://leetcode.com/problems/merge-two-sorted-lists/
    */
}
