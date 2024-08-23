#include <bits/stdc++.h>
using namespace std;

bool comp(pair <int,int> & a , pair <int,int> & b){
    return a.second< b.second;
}

vector <pair<int,int>> ActivitySelection(vector <pair<int,int>> &nums,int n){
    sort(nums.begin(),nums.end(),comp);
    vector <pair<int,int>> result;
    int sec = nums[0].second;
    result.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if (nums[i].first > sec){
            result.push_back(nums[i]);
            sec = nums[i].second;
        }
    }
    return result;
}









int main(){
    vector<pair<int, int> > nums;

    nums.push_back({1, 2});
    nums.push_back({3, 9});
    nums.push_back({1, 2});
    nums.push_back({5, 9});
    nums.push_back({5, 9});
    nums.push_back({5, 7});
    nums.push_back({8, 9});
    
    vector <pair <int,int>> ans = ActivitySelection(nums,nums.size());
    
    for(auto pair : ans){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
}