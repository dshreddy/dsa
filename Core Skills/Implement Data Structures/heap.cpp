#include<bits/stdc++.h>
using namespace std;

class Heap {
private:
    vector<int>v;

    int parent(int i) { 
        if(i%2 == 0) return i/2-1;
        else return i/2;
    }

    int left(int i) { return 2*i+1; }

    int right(int i) { return 2*i+2; }

    void heapify_down(int pos) {
        int max = pos, l = left(pos), r = right(pos);
        if(l<v.size() && v[l]>v[max]) max = l;
        if(r<v.size() && v[r]>v[max]) max = r;
        if(max != pos) {
            swap(v[pos], v[max]);
            heapify_down(max);
        }
    }

    void heapify_up(int pos) {
        int max = pos, l = left(pos), r = right(pos);
        if(l<v.size() && v[l]>v[max]) max = l;
        if(r<v.size() && v[r]>v[max]) max = r;
        if(max != pos) {
            swap(v[pos], v[max]);
            heapify_up(parent(pos));
        }
    }

public:

    void push(int n) {
        v.push_back(n);
        heapify_up(parent(v.size()-1));
    }

    void pop() {
        swap(v[0], v[v.size()-1]);
        v.erase(v.end()-1);
        heapify_down(0);
    }

    int top() { return v[0]; }
};

int main() {
    Heap h;
    h.push(1);
    h.push(-1);
    cout<<h.top()<<"\n";
    h.push(10);
    cout<<h.top()<<"\n";
    h.pop();
    cout<<h.top()<<"\n";
}
