class Solution {
private:
    // bool interLeaveHelper(int ind1, int ind2, string s1, string s2, string s3, vector<vector<bool>>& dp){
    //     if(ind1 == s1.size() && ind2 == s2.size()){
    //         return true;
    //     }

    //     if(dp[ind1][ind2] == true){
    //         return dp[ind1][ind2];
    //     }

    //     if(ind1 < s1.size() && s1[ind1] == s3[ind1 + ind2]){
    //         if(interLeaveHelper(ind1 + 1, ind2, s1, s2, s3, dp)){
    //             return dp[ind1][ind2] = true;
    //         }
    //     }
                
                
    //     if(ind2 < s2.size() && s2[ind2] == s3[ind1 + ind2]){
    //         if(interLeaveHelper(ind1, ind2 + 1, s1, s2, s3, dp)){
    //             return dp[ind1][ind2] = true;
    //         }
    //     }

    //     dp[ind1][ind2] = false;
    //     return dp[ind1][ind2];
    // }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[s1.size()][s2.size()] = true;
        for(int i = s1.size(); i >= 0;i--){
            for(int j = s2.size(); j >= 0;j--){
                if(i < s1.size() && s1[i] == s3[i+j] && dp[i+1][j]){
                    dp[i][j] = true;
                }

                if(j < s2.size() && s2[j] == s3[i+j] && dp[i][j+1]){
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
};