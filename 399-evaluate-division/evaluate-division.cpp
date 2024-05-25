class Solution {
private:
    double bfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>& adj){
        if(adj.find(src) == adj.end() || adj.find(dest) == adj.end()){
            return -1;
        }

        unordered_map<string, bool> visited;
        queue<pair<string, double>> q;
        q.push({src, 1});
        visited[src] = true;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();


            string node = curr.first;
            double weight = curr.second;

            if(node == dest){
                return weight;
            }

            for(auto nei : adj[node]){
                if(visited.count(nei.first) == 0){
                    q.push({nei.first, nei.second * weight});
                    visited[nei.first] = true;
                }
            }
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0;i < equations.size();i++){
            auto current = equations[i];
            string u = current[0];
            string v = current[1];
            double value = values[i];
            adj[u].push_back({v, value});
            adj[v].push_back({u, 1/value});
        }


        for(auto q : queries){
            string src = q[0];
            string dest = q[1];
            res.push_back(bfs(src, dest, adj));
        }
        return res;
    }
};