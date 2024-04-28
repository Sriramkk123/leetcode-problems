class Solution {
public:
    vector<vector<int>> adj;
    vector<int> sum;
    vector<int> count;
    void build_graph(int n, vector<vector<int>>& edges){
        adj.resize(n);
        for(auto& e: edges){
            int v=e[0], w=e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);       
        }
    }
    void dfs(int i, int parent=-1){
        for(int j: adj[i]){
            if (j==parent) continue;
            dfs(j, i);
            count[i]+=count[j];
            sum[i]+=sum[j]+count[j];
        }
    }
    void reroot(int i, int parent, int n){
        for (int j: adj[i]){
            if (j==parent) continue;
            sum[j]=sum[i]+n-2*count[j];
            reroot(j, i, n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        build_graph(n, edges);
        sum.assign(n, 0);
        count.assign(n, 1);
        dfs(0);
        reroot(0, -1, n);
        return sum;
    }
};