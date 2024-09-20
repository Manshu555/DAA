#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low; 
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j)  swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]); 
    return j;
}

void quicksort(int arr[], int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h); 
        quicksort(arr, l, p - 1); 
        quicksort(arr, p + 1, h);
    }
}

int main() {
    int arr[] = {5, 6, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1); 
    for (int i : arr) {
        cout << i << " "; 
    }
    return 0;
}
// https://youtu.be/7h1s2SojIRw?si=61bO_k0D6QfqgWKe
