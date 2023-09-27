#include<bits/stdc++.h>
#define int long long int
using namespace std;

class MinHeap {
public:
    vector<int>min_heap;

    MinHeap() {}

    int parent(int i) {
        if(i==0) return 0;
        else if(i%2!=0) return i/2;
        else return (i-1)/2;
    }

    void heapify_down(int n, int i) {

        int min = i, l = (2*i)+1, r = (2*i)+2;

        if(l<n && min_heap[l]<min_heap[min]) min = l;
        if(r<n && min_heap[r]<min_heap[min]) min = r;

        if(min!=i)
        {
            swap(min_heap[i],min_heap[min]);
            heapify_down(n,min);
        }
    }
    void heapify_up(int n, int i) {

        int min = i, l = (2*i)+1, r = (2*i)+2;

        if(l<n && min_heap[l]<min_heap[min]) min = l;
        if(r<n && min_heap[r]<min_heap[min]) min = r;

        if(min!=i)
        {
            swap(min_heap[i],min_heap[min]);
            heapify_up(n, parent(i));
        }
    }

    //O(1)
    int top() {
        if(min_heap.size() >= 1) return min_heap[0];
        return -1;
    }

    //O(log n)
    void push(int num) {

        if(min_heap.size()==0) min_heap.push_back(num);
        else {

            min_heap.push_back(num);
            int p = parent(min_heap.size()-1);
            heapify_up(min_heap.size(),p);
        }
    }

    //O(log n)
    void pop() {

        if(min_heap.size() > 0) {

            swap(min_heap[0],min_heap[min_heap.size()-1]);
            min_heap.pop_back();
            heapify_down(min_heap.size(), 0);
        }
    }

    void print_heap() {

        for(int i=0; i<min_heap.size(); i++) {
            cout<<min_heap[i]<<"\t";
        }
        cout<<"\n";
    }
};

signed main() {
    MinHeap hp = MinHeap();

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