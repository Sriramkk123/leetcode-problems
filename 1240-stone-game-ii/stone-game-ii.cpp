class Solution {
private:
    int stoneGameIIHelper(int index, int m, 
                        vector<int>& suffixSum, vector<int>& piles, vector<vector<int>>& dp){
        if(index + 2 * m >= suffixSum.size()){
            return suffixSum[index];
        }

        if(dp[index][m] != -1){
            return dp[index][m];
        }

        int res = INT_MAX;
        for(int i = 1;i <= 2 * m;i++){
            res = min(
                res,
                stoneGameIIHelper(index + i, max(i, m), suffixSum, piles, dp)
            );
        }
        return dp[index][m] = suffixSum[index] - res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> suffixSum = piles;
        for(int i = n - 2;i >= 0;i--){
            suffixSum[i] += suffixSum[i + 1];
        }
        return stoneGameIIHelper(0, 1, suffixSum, piles, dp);
    }
};