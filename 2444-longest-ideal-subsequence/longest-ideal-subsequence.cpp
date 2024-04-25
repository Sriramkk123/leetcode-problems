class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        int res = 0;
        for(char c : s){
            int longest = 1;
            int current = c - 'a';
            for(int i = 0;i < 26;i++){
                if(abs(current - i) <= k)
                longest = max(longest, 1 + dp[i]);
            }
            dp[current] = longest;
            res = max(res, longest);
        }
        return res;
    }
};