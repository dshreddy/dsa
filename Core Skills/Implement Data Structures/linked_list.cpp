#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node *next;

    Node() {
        data = -1;
        next = nullptr;
    }

    Node(int x) {
        data = x;
    }

    Node(Node *p) {
        next = p;
    }

    Node(int x, Node *p) {
        data = x;
        next = p;
    }
};

class LinkedList {
public: 
    Node * head = nullptr, * tail = nullptr;

    LinkedList() {}

    void insertAtTail(int n) {
        if(head == nullptr) {
            head = new Node(n);
            tail = head;
        } else {
            Node * t = new Node(n);
            tail->next = t;
            tail = t;
        }
    }

    void insertAtHead(int n) {
        Node * New = new Node(n);
        New->next = head;
        head = New;
    }

    void insertAtPos(int i, int n) {
        if(i == 0) {
            insertAtHead(n);
            return;
        }

        Node *p = head, *q = head->next, *New = new Node(n);
        for(int j=0; j<i-1; j++) {
            p = q;
            if(!q) {
                cout<<"Error1\n";
                return;
            }
            q = q->next;
        }

        p->next = New;
        New->next = q;
    }

    void deleteAtHead() {
        head = head->next;
    }

    void deleteAtPos(int pos) {
        if(pos == 0) {
            deleteAtHead();
            return;
        }

        Node *p = head, *q = head->next;
        for(int j=0; j<pos-1; j++) {
            p = q;
            if(!q) {
                cout<<"Error2\n";
                return;
            }
            q = q->next;
        }

        if(q) p->next = q->next;
        else cout<<"Error3\n";
    }

    void print() {
        Node *t = head;
        while(t) {
            cout<<t->data<<"\t";
            t = t->next;
        }
        cout<<"\n";
    }
};

int main() {
    LinkedList l;
    for(int i=0; i<10; i++) l.insertAtPos(i,i+1);
    l.print();

    l.deleteAtPos(9);
    l.print();

    l.deleteAtPos(0);
    l.print();

    l.deleteAtPos(5);
    l.print();
}
