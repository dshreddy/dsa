#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int p, int m, int q) {

    int t[q-p+1];
    int i = p, j = m+1, k = 0;

    while(i<=m && j<=q) {
        if(arr[i]<arr[j]) t[k++] = arr[i++];
        else t[k++] = arr[j++];
    }

    while(i<=m) t[k++] = arr[i++];
    while(j<=q) t[k++] = arr[j++];

    for(int x=p; x<=q; x++) arr[x] = t[x-p];
}

void mergeSort(int arr[], int p, int q) {
    if(p<q) {
        int m = (p+q)/2;
        mergeSort(arr, p, m);
        mergeSort(arr, m+1, q);
        merge(arr, p, m, q);
    }
}

int main() {
    int arr[] = {7,4,1,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // Tita(N * logN)
    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout<<arr[i]<<"\t";
    cout<<"\n";
}