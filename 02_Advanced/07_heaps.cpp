#include<bits/stdc++.h>
#define int long long int

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int> > small; //maxheap
    priority_queue<int, vector<int>, greater<int> > large; //minheap

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(small.size()==0) small.push(num);
        else {
            
            if( num > small.top() ) large.push(num);
            else small.push(num);

            int s1 = small.size(), s2 = large.size();

            if( (s1-s2) > 1 ) {

                int t = small.top();
                small.pop();
                large.push(t);
            } 
            else if( (s2-s1) > 1) {

                int t = large.top();
                large.pop();
                small.push(t);
            }
        }
    }
    
    double findMedian() {

        int s1 = small.size(), s2 = large.size();

        if(s1 > s2) return small.top();
        else if(s1 < s2) return large.top();
        else return (small.top()+large.top())/2.0;
    }
};

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;

   /*
    https://leetcode.com/problems/find-median-from-data-stream/
    https://leetcode.com/problems/sliding-window-median/
    https://leetcode.com/problems/ipo/
   */
}

