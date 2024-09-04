// Prim's Algorithm in C++
#include <bits/stdc++.h>
using namespace std;
int prims_algorithm(vector<vector<int>> &G, int V)
{
    int TotalCost = 0;
    int no_edge = 0;
    vector<bool> selected(V, false);
    selected[0] = true;
    int x;
    int y;
    cout << "Edge" << " : " << "Weight" << endl;
    while (no_edge < V - 1)
    {
        int min = INT_MAX;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        TotalCost += G[x][y];
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    return TotalCost;
}
int main()
{
    int V;
    cin >> V;
    vector<vector<int>> G (V,vector <int> (V));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>G[i][j];
        }
    }
    cout << prims_algorithm(G, V);

    return 0;
}
