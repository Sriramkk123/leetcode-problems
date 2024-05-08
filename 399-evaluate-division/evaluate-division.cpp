class Solution {
public:
    double bfs(string src, string target, unordered_map<string, vector<pair<string, double>>>& adj){
        if(adj.find(src) == adj.end() || adj.find(target) == adj.end()){
            return -1;
        }
        unordered_map<string, bool> visited;
        queue<pair<string, double>> q;
        q.push({src, 1});
        visited[src] = true;
        while(!q.empty()){  
            auto curr = q.front();
            q.pop();
            double w = curr.second;
            string tar = curr.first;
            if(tar == target){
                return w;
            }

            for(auto neighbours : adj[tar]){
                double weight = neighbours.second;
                string node = neighbours.first;
                if(!visited[node]){
                    q.push({node, w*weight});
                    visited[node] = true;
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0;i < equations.size();i++){
            auto eq = equations[i];
            adj[eq[0]].push_back({eq[1], values[i]});
            adj[eq[1]].push_back({eq[0], 1 / values[i]});
        }
        for(int i = 0;i < queries.size();i++){
            auto query = queries[i];
            string source = query[0];
            string target = query[1];
            res.push_back(bfs(source, target, adj));
        }
        return res;
    }
};