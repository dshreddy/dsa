#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int p, int q) {
    if(p<q) {

        int pivot = arr[q];
        int split = p;

        for(int i = p; i<q; i++) if(arr[i] < pivot) swap(arr[i], arr[split++]);
        swap(arr[q], arr[split]);
        
        quickSort(arr, p, split-1);
        quickSort(arr, split+1, q);
    }
}

int main() {
    int arr[] = {7,4,1,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // O(N * logN)
    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout<<arr[i]<<"\t";
    cout<<"\n";
}