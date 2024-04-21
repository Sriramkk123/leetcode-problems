class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination){
            return true;
        }
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(n, false);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(source);
        visited[source] = false;
        while(!q.empty()){
            int current = q.front();
            if(destination == current){
                return true;
            }
            q.pop();
            for(auto node : graph[current]){
                if(!visited[node]){
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
        return false;
    }
};