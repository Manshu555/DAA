#include <iostream>
using namespace std;

void MaxHeapify(int arr[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, n);
    }
}
int main(){
    int arr[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(int);
    int i = 2; // Testing with the root at index 2
    MaxHeapify(arr, i, n);
    cout << "Before MAX-HEAPIFY: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    MaxHeapify(arr, i, n);

    cout << "After MAX-HEAPIFY: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}