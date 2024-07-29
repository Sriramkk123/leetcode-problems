class Solution {
private:
    int numTeamsHelper(int index, bool ascend, int count, vector<int>& rating, vector<vector<vector<int>>>& dp){
        if(count == 3){
            return 1;
        }

        if(index == rating.size()){
            return 0;
        }

        if(dp[index][ascend][count] != -1){
            return dp[index][ascend][count];
        }

        int res = 0;
        for(int j = index + 1;j < rating.size();j++){
            if(ascend && rating[index] < rating[j]){
                res += numTeamsHelper(j, ascend, count + 1, rating, dp);
            }
            if(!ascend && rating[index] > rating[j]){
                res += numTeamsHelper(j, ascend, count + 1, rating, dp);
            }
        }
        return res;
    }
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int n = rating.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(4, -1)));
        // for(int i = 0;i < n;i++){
        //     res += numTeamsHelper(i, true, 1, rating, dp) + numTeamsHelper(i, false, 1, rating, dp);
        // }
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