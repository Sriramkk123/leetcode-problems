class Solution {
public:
    int get_min(vector<int> arr){
        int mini = INT_MAX;
        for(auto ele : arr){
            mini = min(ele, mini);
        }
        return mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minSum = INT_MAX;
        vector<int> prev_dp;
        for(auto ele : grid[0]){
            prev_dp.push_back(ele);
        }
        for(int i = 1;i < grid.size();i++){
            vector<int> dp(grid[0].size(), INT_MAX);
            for(int j = 0;j < grid[0].size();j++){
                for(int k = 0;k < prev_dp.size();k++){
                    if(k != j){
                        dp[j] = min(
                            dp[j],
                            grid[i][j] + prev_dp[k]
                        );
                    }
                }
            }
            prev_dp = dp;
        }
        return get_min(prev_dp);
    }
};