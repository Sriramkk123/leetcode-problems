class Solution {
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int>& curr){
        vis[node] = true;
        for(auto nei : adj[node]){
            if(!vis[nei]){
                curr.push_back(nei);
                dfs(nei, vis, adj, curr);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge : edges){
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> res;
        for(int i = 0;i < n;i++){
            vector<int> vis(n);
            vector<int> curr;
            dfs(i, vis, adj, curr);
            sort(curr.begin(), curr.end());
            res.push_back(curr);
        }
        return res;
    }
};