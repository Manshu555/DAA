#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    int V; 
    list<iPair> *adj; 

public:
    Graph(int V);

    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w)); 
}
void Graph::shortestPath(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << " \t\t " << dist[i] << endl;
}

int main() {
    int V = 6; 
    Graph g(V);
    g.addEdge(0,1,4);
    g.addEdge(0,3,9);
    g.addEdge(0,2,8);
    g.addEdge(1,3,2);
    g.addEdge(1,5,3);
    g.addEdge(1,4,7);
    g.addEdge(4,5,6);
    g.addEdge(2,3,5);
    g.addEdge(2,5,1);
    g.addEdge(3,5,5);
    g.shortestPath(0);
    return 0;
}
