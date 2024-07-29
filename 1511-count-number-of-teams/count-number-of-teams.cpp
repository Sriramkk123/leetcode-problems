class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int n = rating.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(4, 0)));
        for(int i = 0;i < n;i++){
            dp[i][0][1] = 1;
            dp[i][1][1] = 1;
        }

        for(int count = 2;count <= 3;count++){
            for(int i = 0;i < n;i++){
                for(int j = i + 1;j < n;j++){
                    if(rating[i] < rating[j]){
                        dp[j][0][count] += dp[i][0][count-1];
                    }
                    if(rating[i] > rating[j]){
                        dp[j][1][count] += dp[i][1][count-1];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            res += dp[i][0][3] + dp[i][1][3];
        }
        return res;
    }
};