class Solution {
private:
    vector<vector<int>> lcs(string text1, string text2){
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp = lcs(str1, str2);
        int i = n;
        int j = m;
        string s="";
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                s += str1[i-1];
                i--;
                j--;
            } else if(dp[i][j-1] > dp[i-1][j]){
                s += str2[j-1];
                j--;
            }   else {
                s += str1[i-1];
                i--;
            }
        }
        while(i > 0){
            s += str1[i-1];
            i--;
        }
        while(j > 0){
            s += str2[j-1];
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};