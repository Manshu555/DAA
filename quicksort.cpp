#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
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
    int n = sizeof(arr) / sizeof(int);
    quicksort(arr, 0, n);
    for (int i : arr)
        cout << i << " ";
}
