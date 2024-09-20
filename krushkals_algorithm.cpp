// #include <bits/stdc++.h>
// using namespace std;

// int findParent(int u, vector<int>& parent) {
//     if (parent[u] == u)
//         return u;
//     return parent[u] = findParent(parent[u], parent); // Path compression
// }

// void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
//     u = findParent(u, parent);
//     v = findParent(v, parent);

//     if (rank[u] < rank[v]) {
//         parent[u] = v;
//     } else if (rank[u] > rank[v]) {
//         parent[v] = u;
//     } else {
//         parent[v] = u;
//         rank[u]++;
//     }
// }

// int kruskalMST(int V, vector<vector<int>>& edges) {
//     // Sort all edges based on weight
//     sort(edges.begin(), edges.end(), [](vector<int>& a,vector<int>& b) {
//         return a[2] < b[2];
//     });

//     vector<int> parent(V);
//     vector<int> rank(V, 0);
//     vector<vector<int>> result; // Store the result MST

//     // Initialize the parent array for each vertex
//     for (int i = 0; i < V; i++) {
//         parent[i] = i;
//     }

//     // Process each edge in the sorted order
//     for (auto edge : edges) {
//         int u = edge[0];
//         int v = edge[1];
//         int weight = edge[2];

//         int setU = findParent(u, parent);
//         int setV = findParent(v, parent);

//         // If u and v belong to different sets, include this edge in the MST
//         if (setU != setV) {
//             result.push_back(edge);
//             unionSets(setU, setV, parent, rank);
//         }
//     }

//     int totalWeight = 0;
//     for (auto edge : result) {
//         cout << edge[0] << " - " << edge[1] << " : " << edge[2] << endl;
//         totalWeight += edge[2];
//     }
//     return totalWeight;
// }

// int main() {
//     int V;
//     cin>>V;
//     vector<vector<int>> edges(V+1,vector <int>(3)) ; // edge = vertices +1
//     for(int i=0;i<V+1;i++){
//         for(int j=0;j<3;j++){
//             cin>>edges[i][j];
//         }
//     }
//     cout<<kruskalMST(V, edges);

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DSU Code
    vector<int> parent;
    vector<int> rank;

    // Initialize the DSU structure
    Solution(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    int find(int x) {
        if (x != parent[x]) 
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        // Union by rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    static bool comp(vector<int>& a,vector<int>& b){
      return a[2]<b[2];
    }

    int Kruskal(vector<vector<int>>& vec, int n) {
      sort(vec.begin(),vec.end(),comp);
      int sum=0;
      for(auto temp : vec){
        int u = temp[0];
        int v = temp[1];
        int wt = temp[2];
        if (find(u) != find(v)){
          sum += wt;
          Union(u,v);
        }
      }
      return sum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
    
    Solution s(n);
    cout << s.Kruskal(vec, n);
}
