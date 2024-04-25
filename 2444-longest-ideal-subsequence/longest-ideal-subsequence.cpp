class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(27,0);
        int n = s.size();
        for(int i = n - 1;i >= 0;i--){
            char current = s[i];
            int index = current - 'a';
            int maxi = INT_MIN;

            int left = max((index - k), 0);
            int right = min((index + k), 26);

            for(int j = left;j <= right;j++){
                maxi = max(maxi, dp[j]);
            }

            dp[index] = maxi + 1;
        }

        int maxi = INT_MIN;
        for(int i = 0;i < 27;i++){
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};