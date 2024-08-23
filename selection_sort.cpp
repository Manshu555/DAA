#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n){
    if (n<=1) return;
    for(int i=0;i<n;i++) {
        int min_index = i;
        for(int j=i+1;j<n;j++) 
            if (arr[min_index] > arr[j]) min_index = j;
        swap(arr[min_index],arr[i]);
    }   
}

void insertionSort(int arr[],int n) { 
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int arr[] = {9,7,99,10,3,12,34};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr,n);
    selectionsort(arr,n);
    for(int i : arr) cout<<i<<" ";
    return 0;
}

