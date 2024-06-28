class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, set<int>> adj;
        for(auto road : roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }
        priority_queue<pair<int,int>> pq;
        for(auto cand : adj){
            int edge = cand.first;
            int connectionSize = cand.second.size();
            pq.push({connectionSize, edge}); 
        }
        int imp = n;
        vector<int> importance(n, 0);
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            importance[curr.second] = imp;
            imp--;
        }
        long long res = 0;
        for(auto road : roads){
            res = res + importance[road[0]] + importance[road[1]];
        }
        return res;
    }
};