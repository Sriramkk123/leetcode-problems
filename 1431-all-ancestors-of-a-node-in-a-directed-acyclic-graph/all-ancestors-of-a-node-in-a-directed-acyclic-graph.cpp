class Solution {
private:
    void dfs(int node, int anc, vector<int> &vis, vector<int> adj[],vector<vector<int>>& res){
        vis[node] = true;
        for(auto nei : adj[node]){
            if(!vis[nei]){
                res[anc].push_back(nei);
                dfs(nei, anc, vis, adj, res);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge : edges){
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> res(n);
        for(int i = 0;i < n;i++){
            vector<int> vis(n);
            dfs(i, i, vis, adj, res);
            if(!res.empty()){
                sort(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};