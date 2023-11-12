class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> umap;   //bus_stop belongs to which route (can be multiple)
        for(int i=0; i<routes.size(); ++i){
            for(auto r : routes[i]){
                umap[r].push_back(i);
            }
        }
        unordered_set<int> visited; //if bus_stop is visited
        queue<pair<int, int>> q;    //bus_stop and num of bus taken so far
        q.push({source, 0});
        visited.insert(source);
        
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int stop = f.first;
            int bus_num = f.second;
            if(stop == target){
                return bus_num;
            }
            for(auto r : umap[stop]){       // r --> routes
                for(auto b : routes[r]){    // b --> bus stops
                    if(visited.find(b) == visited.end()){
                        q.push({b, bus_num + 1});
                        visited.insert(b);
                    }
                }
                routes[r].clear();
            }
        }
        
        return -1;
    }
};