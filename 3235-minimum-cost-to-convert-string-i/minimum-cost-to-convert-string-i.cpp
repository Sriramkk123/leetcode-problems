class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        if (source.size() != target.size()) {
            return -1;
        }
        unordered_map<char, vector<pair<char, long long>>> adj;
        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> distance(26, vector<long long>(26, 1e18));
        
        for (int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            distance[from][to] = min(distance[from][to], (long long)cost[i]);
        }

        for (int i = 0; i < 26; i++) {
            distance[i][i] = 0;
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < source.size(); i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (distance[from][to] == 1e18) {
                return -1;
            }
            res += distance[from][to];
        }

        return res;
    }
};