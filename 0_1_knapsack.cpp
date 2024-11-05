#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int> > K(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}
/*
Time Complexity: O(N * W). As redundant calculations of states are avoided
Auxiliary Space: O(N * W) As we are using a 1-D array instead of a 2-D array
*/
