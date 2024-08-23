#include <bits/stdc++.h>
using namespace std;

void MaxHeapify(int arr[], int i, int n) {
    int l = 2*i + 1; 
    int r = 2*i + 2;  
    int largest = i;

    if (l < n && arr[l] > arr[largest]) 
        largest = l;
    if (r < n && arr[r] > arr[largest]) 
        largest = r;
    if (largest != i) {
        swap(arr[largest], arr[i]);
        MaxHeapify(arr, largest, n);
    }
}

void BuildHeap(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        MaxHeapify(arr, i, n);
    }
}

void HeapSort(int arr[], int n) {
    BuildHeap(arr, n);

    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        MaxHeapify(arr, 0, i); 
    }
}

int main(){
    int arr[] = {5,2,3,44,52};
    int n = sizeof(arr)/sizeof(int);
    HeapSort(arr,n);
    for(int i : arr) cout<<i<<" ";
    return 0;
}