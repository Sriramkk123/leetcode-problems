class Solution {
private:
    string uniqueCharacters(string s){
        string res = "";
        int n = s.size();
        int i = 0;
        while(i < n){
            char currentChar = s[i];
            res += currentChar;
            
            if(i < n && s[i] == currentChar){
                i++;
            }
        }
        return res;
    }
    int strangePrinterHelper(int start, int end, string s, vector<vector<int>>& dp){
        if(start > end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int minTurns = 1 + strangePrinterHelper(start + 1, end, s, dp);
        for(int k = start + 1;k <= end;k++){
            if(s[k] == s[start]){
                int turnsWithMatch = strangePrinterHelper(start, k - 1, s, dp) + 
                                    strangePrinterHelper(k + 1, end, s, dp);
                minTurns = min(minTurns, turnsWithMatch);
            }
        }

        return dp[start][end] = minTurns;
    }
public:
    int strangePrinter(string s) {
        string unique = uniqueCharacters(s);
        int n = unique.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return strangePrinterHelper(0, n - 1, unique, dp);
    }
};
