#include <bits/stdc++.h>
using namespace std;
double Huffmann_Algorithm(vector <int>& nums,int n,int M){
    vector <int> size(n);
    sort(nums.begin(),nums.end(), greater<int>());
    for(int i=0;i<n-1;i++) size[i] = i+1;
    size[n-1] = n-1;
    int ans=0;
    for(int i=0;i<n;i++) ans += size[i]*nums[i];
    return (double)ans/M; // number of bits per character
}
int main(){
    int n,M;
    cin>>n>>M; // number of element in vector and Maximum Capacity
    vector <int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i]; // Inputs in Vector
    cout<<Huffmann_Algorithm(nums,n,M);
    return 0;
}
