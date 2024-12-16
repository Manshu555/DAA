class Graph {
public:
    vector <vector <int>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adj.resize(n, vector<int>(n, 1e9));
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];
            adj[u][v] = c;
        }

        for(int i=0;i<n;i++) adj[i][i]= 0;

        //floydwarshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                adj[i][j] = min(adj[i][j] , adj[i][u] + cost + adj[v][j]);
            }
        }
    }
    int shortestPath(int node1, int node2) {
        int x = adj[node1][node2];
        return (x == 1e9) ?  -1 : x; 
    }
};
