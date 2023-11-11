class Graph {
private:
    vector<pair<int, int>> adj[101];
    int N;
public:
    Graph(int n, vector<vector<int>>& edges) {
        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
        N = n;
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int dist[N];
        for(int i=0; i<N; ++i){
            dist[i] = 1e8;
        }
        pq.push({0, node1});
        dist[node1] = 0;
        while(!pq.empty()){
            auto t = pq.top(); pq.pop();
            int v = t.second, w = t.first;
            if(v == node2){
                return w;
            }
            for(auto i : adj[v]){
                if(dist[i.first] > dist[v] + i.second){
                    dist[i.first] = dist[v] + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */