class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1){
            return 0;
        }
        vector<vector<long long >> dp(n + 1, vector<long long>(m + 1, 0));
        for(int i = n - 1; i >= 0;i--){
            for(int j = m - 1; j >= 0;j--){
                if(i == n - 1 && j == m - 1){
                    dp[i][j] = 1;
                } else if(obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return (int)dp[0][0];
    }
};