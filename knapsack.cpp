#include <bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int,int>, double>& a, pair<pair<int,int>, double>& b) {
    return a.second > b.second;
}

double knapsack(vector<pair<int,int>>& object, int n, int M) {
    vector<pair<pair<int,int>, double>> mp;
    for(auto& pair : object) {
        mp.push_back({pair, double(pair.first) / pair.second});
    }

    sort(mp.begin(), mp.end(), comp);
    double Total_profit = 0;
    int x_taken = 0;

    for(auto& pair : mp) {
        if (M <= 0) break;
        int weight = pair.first.second;  // weight
        int profit = pair.first.first;  // profit
        if (weight < M) {
            x_taken = weight;
        } else {
            x_taken = M;
        }

        Total_profit += (double(x_taken) / weight) * profit;
        cout << (double(x_taken) / weight) * profit<< " " << Total_profit << endl;
        M -= x_taken;
    }
    return Total_profit;
}

int main() {
    int n, M;  // number of objects
    cin >> n;
    cin >> M;
    vector<pair<int,int>> object;

    for(int i = 0; i < n; i++) {
        int profit, weight;
        cin >> profit >> weight;
        object.push_back({profit, weight});
    }
    cout << knapsack(object, n, M);
}
