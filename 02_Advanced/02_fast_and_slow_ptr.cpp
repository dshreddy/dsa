#include<bits/stdc++.h>
using namespace std;

class ListNode 
{
public:
    int val;
    ListNode* next;
};

// Time: O(n), Space: O(1)
ListNode* middleOfList(ListNode* head) 
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Time: O(n), Space: O(1)
bool hasCycle(ListNode* head) 
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Time: O(n), Space: O(1)
ListNode* cycleStart(ListNode* head) 
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return nullptr;
    
    ListNode *slow2 = head;
    while (slow != slow2) 
    {
        slow = slow->next;
        slow2 = slow2->next;
    }
    return slow;
}

int main()
{
    /*
    https://leetcode.com/problems/middle-of-the-linked-list/
    https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
    https://leetcode.com/problems/linked-list-cycle/
    https://leetcode.com/problems/linked-list-cycle-ii/
    https://leetcode.com/problems/find-the-duplicate-number/
    */
}
