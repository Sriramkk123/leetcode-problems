class Solution {
private:
    int maxProfitHelper(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind == prices.size()){
            return 0;
        }

        if(cap == 0){
            return 0;
        }

        if(dp[ind][buy][cap] != -1){
            return dp[ind][buy][cap];
        }

        if(buy == 1){
            return dp[ind][buy][cap] = max(
                -prices[ind] + maxProfitHelper(ind + 1, 0, cap, prices, dp),
                0 + maxProfitHelper(ind + 1, 1, cap, prices, dp)
            );
        } 

        return dp[ind][buy][cap] = max(
            prices[ind] + maxProfitHelper(ind + 1, 1, cap - 1, prices, dp),
            0 + maxProfitHelper(ind + 1, 0, cap, prices, dp)
        );
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),
                vector<vector<int>>(2, vector<int>(3, -1)));
        return maxProfitHelper(0, 1, 2, prices, dp);
    }
};