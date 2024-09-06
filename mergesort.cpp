#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int h, int mid) {
    int i = l;
    int j = mid + 1;
    vector<int> b(h - l + 1);
    int k = 0;

    while (i <= mid && j <= h) {
        if (arr[i] < arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }

    while (i <= mid) b[k++] = arr[i++];
    while (j <= h) b[k++] = arr[j++];

    for (int i = 0; i < b.size(); i++) arr[l + i] = b[i];
}

void mergesort(vector<int>& arr, int l, int h) {
    if (l >= h) return;
    int mid = (l + h) / 2;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, h);
    merge(arr, l, h, mid);
}

int main(){
    vector <int> arr = {4,3,6,8,2};
    mergesort(arr,0,arr.size()-1);
    for(int i : arr) cout<<i<<" ";
    return 0;
}
