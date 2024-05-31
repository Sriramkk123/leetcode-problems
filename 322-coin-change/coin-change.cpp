class Solution {
private:
    int coinChangeHelper(int index, vector<int>& coins, int amount,
                        vector<vector<int>>& dp){
        if(index == coins.size()){
            if(amount == 0){
                return 0;
            }
            return INT_MAX - 1;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        int res = -1;
        if(coins[index] > amount){
            int skip = 0 + coinChangeHelper(index + 1, coins, amount, dp);
            res = skip;
        }

        if(coins[index] <= amount){
            amount -= coins[index];
            int take = 1 + coinChangeHelper(index, coins, amount, dp);
            amount += coins[index];
            int doNotTake = 0 + coinChangeHelper(index + 1, coins, amount, dp);
            res = min(take, doNotTake);
        }
        return dp[index][amount] = res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(12 + 1, vector<int>(amount + 1, -1)); 
        int res = coinChangeHelper(0, coins, amount, dp);
        return  res == INT_MAX - 1 ? - 1 : res;
    }
};