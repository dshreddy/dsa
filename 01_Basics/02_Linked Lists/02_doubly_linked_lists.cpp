#include<bits/stdc++.h>
#define int long long int
using namespace std;

class Node {
public :
    int val;
    Node * next = NULL;
    Node * prev = NULL;

    inline Node() {}

    inline Node(int x) {val = x;}
};

class doublyList{
public:
    Node *head = NULL;
    Node *tail = NULL;
    //O(n)
    void Print()
    {
        Node *current = head; 
        while(current)
        {
            cout<<current->val<<"\t";
            current = current->next;
        }
        cout<<endl;
    }
    //O(n)
    void InsertAt(int i, int val) 
    {
        Node *new_node = new Node(val);

        if(head == NULL) {
            head = new_node;
            tail = new_node; // Update the tail when inserting the first node
        }
        else {

            if(i==0) 
            {
                head->prev = new_node;
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
                new_node->prev = p;
                new_node->next = q;
                if(q) q->prev = new_node;
                else tail = new_node;
            }
        }
    }
    //O(n)
    void RemoveAt(int i) 
    {
        if(head == NULL) return;
        else {

            if(i==0) 
            {
                head = head->next;
                if (head == NULL) tail = NULL;
            }
            else 
            {
                Node *p = head,*q = head->next;
                for(int j=0; j<i-1; j++)
                {
                    p = p->next;
                    if(q) q = q->next; 
                }
                p->next = q->next;
                if(q->next) q->next->prev = p;
                else tail = p;
            }
        }
    } 
};

signed main() 
{
    doublyList dll;

    //inserting at end
    for(int i=0; i<10; i++)  dll.InsertAt(i,i+1);

    //inserting at start
    dll.InsertAt(0,0);

    //inserting at Middle
    dll.InsertAt(1,11);

    dll.Print();

    //Removing at middle
    dll.RemoveAt(1);

    //Removing at end
    dll.RemoveAt(8);

   //Removing at start
    dll.RemoveAt(0);

    dll.Print(); 
    return 0;
  /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/design-linked-list/
    https://leetcode.com/problems/design-browser-history/
  */  
}
