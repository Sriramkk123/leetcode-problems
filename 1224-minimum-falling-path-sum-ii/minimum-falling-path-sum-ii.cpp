class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp){
        if(row == grid.size() - 1){
            return grid[row][col];
        }

        if(dp[row][col] != -1000){
            return dp[row][col];
        }
        int mini = INT_MAX;
        for(int j = 0;j < grid[0].size();j++){
            if(j != col){
                mini = min(
                    mini,
                    grid[row][col] + solve(grid,row+1,j,dp)
                );
            }
        }
        return dp[row][col] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minSum = INT_MAX;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size() + 1, -1000));
        for(int i = 0;i < grid[0].size();i++){
            minSum = min(minSum, solve(grid, 0, i, dp));
        }
        return minSum;
    }
};