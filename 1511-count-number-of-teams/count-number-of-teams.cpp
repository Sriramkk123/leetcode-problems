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
        return dp[index][ascend][count] = res;
    }
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int n = rating.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(4, -1)));
        for(int i = 0;i < n;i++){
            res += numTeamsHelper(i, true, 1, rating, dp) + numTeamsHelper(i, false, 1, rating, dp);
        }
        return res;
    }
};