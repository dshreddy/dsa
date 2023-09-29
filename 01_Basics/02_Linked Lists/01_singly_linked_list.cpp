#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Main difference between arrays & linked lists are
    Arrays have fixed size, linked list size is not bounded
    In arrays random access of elements at some index is possible while it isn't
   possible in list In arrays all elements are stored in contigous block, while
   in linked list that isn't the case
*/

class Node {
public:

  int val;
  Node *next = NULL;

  inline Node() {}

  inline Node(int x) { val = x; }

  inline Node(int x, Node *n) {
    val = x;
    next = n;
  }

};

class LinkedList {
private:

  Node *head = NULL;

public:

  // O(n)
  void print() 
  {

    Node *current = head;

    while (current) 
    {
      cout << current->val << "\t";
      current = current->next;
    }
    cout << endl;
  }

  // O(n)
  void insertAt(int i, int val) 
  {

    Node *new_node = new Node(val);

    if (head == NULL) head = new_node;
    else 
    {
      if (i == 0) 
      {
        new_node->next = head;
        head = new_node;
      } 
      else 
      {
        Node *p = head, *q = head->next;
        for (int j = 0; j < i - 1; j++) 
        {
          p = p->next;
          if (q) q = q->next;
        }
        p->next = new_node;
        new_node->next = q;
      }
    }
  }

  // O(n)
  void removeAt(int i) 
  {
    if (head == NULL) return;
    else 
    {
      if (i == 0) head = head->next;
      else 
      {
        Node *p = head, *q = head->next;
        for (int j = 0; j < i - 1; j++) 
        {
          p = p->next;
          if (q) q = q->next;
        }
        p->next = q ? q->next : NULL;
      }
    }
  }
};

signed main() {

  LinkedList list;

  // Inserting at end
  for (int i = 0; i < 10; i++) list.insertAt(i, i + 1);

  cout << "Linked List after insertions:" << endl;
  list.print();

  // Removing at middle
  list.removeAt(1);

  // Removing at end
  list.removeAt(8);

  // Removing at start
  list.removeAt(0);

  cout << "Linked List after removals:" << endl;
  list.print();

  return 0;

  /*
  SUGGESTED PROBLEMS
  https://leetcode.com/problems/reverse-linked-list/
  https://leetcode.com/problems/merge-two-sorted-lists/
  */
}
