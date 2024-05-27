class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(row == matrix.size()){
            return 0;
        }
        if(col < 0 || col >= matrix.size()){
            return INT_MAX;
        }

        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }

        int res = matrix[row][col];
        int left = dfs(row + 1, col - 1, matrix, dp);
        int right = dfs(row + 1, col + 1, matrix, dp);
        int bottom = dfs(row + 1, col, matrix, dp);
        int mini = min(left, min(right, bottom));
        return dp[row][col] = res + mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int res = INT_MAX;
        for(int i = 0;i < n;i++){
            res = min(res, dfs(0, i, matrix, dp));
        }
        return res;
    }
};