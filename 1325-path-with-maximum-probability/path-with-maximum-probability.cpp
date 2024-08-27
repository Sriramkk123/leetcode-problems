class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> res(n, 0);
        res[start_node] = 1.0;
        for(int i = 0;i < n - 1;i++){
            bool hasUpdated = false;
            for(int j = 0;j < edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];
                if(res[u] * prob > res[v]){
                    res[v] = res[u] * prob;
                    hasUpdated = true;
                }
                if(res[v] * prob > res[u]){
                    res[u] = res[v] * prob;
                    hasUpdated = true;
                }
            }
            if(!hasUpdated){
                break;
            }
        }
        return res[end_node];
    }
};