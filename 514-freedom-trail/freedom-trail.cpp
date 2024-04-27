class Solution {
public:
    int solve(string ring, string key, int r_index, int k_index, vector<vector<int>> dp){
        if(k_index == key.size()){
            return 0;
        }

        if(dp[r_index][k_index] != -1000){
            return dp[r_index][k_index];
        }

        int res = INT_MAX;
        for(int i = 0;i < ring.size();i++){
            if(ring[i] == key[k_index]){
                int clockWise = abs(i - r_index);
                int anti = ring.size() - abs(i - r_index);
                int min_dist = min(clockWise, anti);
                res = min(
                    res,
                    min_dist + 1 + solve(ring, key, i, k_index + 1, dp)
                );
            }
        }
        return dp[r_index][k_index] = res;
    }
    int findRotateSteps(string ring, string key) {
        // vector<vector<int>> dp(ring.size(), vector<int>(key.size(), -1000));
        // return solve(ring, key, 0, 0, dp);
        vector<int> dp(ring.size(),0);
        for(int i = key.size() - 1; i >= 0;i--){
            vector<int> next_dp(ring.size(), INT_MAX);
            for(int j = 0;j < ring.size();j++){
                for(int k = 0;k < ring.size();k++){
                    if(ring[k] == key[i]){
                        int clockWise = abs(k - j);
                        int anti = ring.size() - abs(k - j);
                        int min_dist = min(clockWise, anti);
                        next_dp[j] = min(
                            next_dp[j],
                            min_dist + 1 + dp[k]
                        );
                    }
                }
            }
            dp = next_dp;
        }
        return dp[0];
    }
};
