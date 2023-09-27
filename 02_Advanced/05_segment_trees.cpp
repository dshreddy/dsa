#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int sum, l, r;
    SegmentTree *left, *right;

    SegmentTree() {}

    SegmentTree(int s, int a, int b){

        sum = s;
        l = a;
        r = b;
        left = nullptr;
        right = nullptr;
    }

    SegmentTree* build(vector<int>& nums, int a, int b){

        if(a==b) return new SegmentTree(nums[a], a , b);
        else
        {
            SegmentTree* root = new SegmentTree(0,a,b);
            int m = (a+b)/2;
            root->left = build(nums, a, m);
            root->right = build(nums, m+1, b);
            root->sum = root->left->sum + root->right->sum;

            return root;
        }
    }

    void update(int index, int val) {

        if(l == r) sum = val;
        else
        {
            int m = (l+r)/2;

            if(index > m) right->update(index, val);
            else left->update(index, val);

            sum = left->sum + right->sum;
        }
    }

    int range(int a, int b) {

        if(l==a && r==b) return sum;
        else
        {
            int m = (l+r)/2;

            if(a>m) return right->range(a,b);
            else if(b<=m) return left->range(a,b);
            else return (left->range(a,m) + right->range(m+1,b));
        }
    }
}; 

int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    SegmentTree s;
    SegmentTree * S = s.build(v,0,v.size()-1);

    for(int i=0; i<v.size(); i++)
    {
        for(int j=i; j<v.size(); j++)
        {
            cout<<"Subarray : ";
            for(int k=i; k<=j; k++) cout<<v[k]<<"\t";
            cout<<endl;

            cout<<"Sum : "<<S->range(i,j)<<endl;
        }
    }
    
    /*
    https://leetcode.com/problems/range-sum-query-mutable/
    https://leetcode.com/problems/queue-reconstruction-by-height/
    https://leetcode.com/problems/my-calendar-i/
    https://leetcode.com/problems/longest-increasing-subsequence-ii/
    */
}