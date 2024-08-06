#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {7,4,1,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // O(N^2)
    for(int i=0; i<n; i++) {
        int j = i-1;
        while(j>=0 && arr[j]>arr[j+1]) {
            swap(arr[j], arr[j+1]);
            j--;
        }
    }

    for(int i=0; i<n; i++) cout<<arr[i]<<"\t";
    cout<<"\n";
}