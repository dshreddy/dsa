#include<bits/stdc++.h>
using namespace std;

// Implementing a stack is trivial using a dynamic array (which we implemented earlier).
class Stack {
private:
    vector<int> stack_;
public:
    Stack() {};
    
    //O(1)
    void push(int n) {
        stack_.push_back(n);       
    }
    //O(1)
    int pop() {
        if(stack_.size() > 0) {

            int res = stack_[stack_.size() - 1];
            stack_.pop_back();
            return res;
        }
        return INT_MIN;
    }
};

int main()
{
    Stack stack;
    stack.push(1);
    cout<<stack.pop()<<endl;

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/baseball-game/
    https://leetcode.com/problems/valid-parentheses/
    https://leetcode.com/problems/min-stack/
    */
}
