#include<bits/stdc++.h>
#define int long long int
using namespace std;

/*
Heap is a balanced binary tree that has 2 properties : 
1) Structure property 
2) Order property
*/

class MaxHeap {
public:
    vector<int>max_heap;

    MaxHeap() {}

    int parent(int i) {
        if(i==0) return 0;
        else if(i%2!=0) return i/2;
        else return (i-1)/2;
    }

    void heapify_down(int n, int i) {

        int max = i, l = 2*i+1, r = 2*i+2;

        if(l<n && max_heap[l]>max_heap[max]) max = l;
        if(r<n && max_heap[r]>max_heap[max]) max = r;

        if(max!=i)
        {
            swap(max_heap[i],max_heap[max]);
            heapify_down(n,max);
        }
    }
    void heapify_up(int n, int i) {

        int max = i, l = 2*i+1, r = 2*i+2;

        if(l<n && max_heap[l]>max_heap[max]) max = l;
        if(r<n && max_heap[r]>max_heap[max]) max = r;

        if(max!=i)
        {
            swap(max_heap[i],max_heap[max]);
            heapify_up(n,parent(i));
        }
    }

    //O(1)
    int top() {
        if(max_heap.size()>0) return max_heap[0];
        return -1;
    }

    //O(log n)
    void push(int num) {

        if(max_heap.size()==0) max_heap.push_back(num);
        else 
        {
            max_heap.push_back(num);
            int p = parent(max_heap.size()-1);
            heapify_up(max_heap.size(), p);
        }
    }

    //O(log n)
    void pop() {
        
        if(max_heap.size()>0) {
            swap(max_heap[0],max_heap[max_heap.size()-1]);
            max_heap.pop_back();
            heapify_down(max_heap.size(),0);
        }
    }

    //O(n)
    void print_heap() {

        for(int i=0; i<max_heap.size(); i++) {
            cout<<max_heap[i]<<"\t";
        }
        cout<<"\n";
    }
};

signed main() {
    MaxHeap hp = MaxHeap();

    hp.push(19);
    hp.push(16);
    hp.push(21);
    hp.push(26);
    hp.push(14);
    hp.push(19);
    hp.push(68);
    hp.push(65);
    hp.push(30);
    hp.print_heap();
    hp.pop();
    hp.print_heap();
    return 0;
}

/*
SUGGESTED PROBLEMS
https://leetcode.com/problems/kth-largest-element-in-a-stream/
https://leetcode.com/problems/last-stone-weight/
https://leetcode.com/problems/k-closest-points-to-origin/
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/