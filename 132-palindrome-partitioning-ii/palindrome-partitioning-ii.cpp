class Solution {
private:
    bool isPallindrome(string& cand){
        if(cand.size() == 1){
            return true;
        }
        int start = 0;
        int end = cand.size() - 1;
        while(start <= end){
            if(cand[start] != cand[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int index = n-1;index >= 0;index--){
            int minCost = INT_MAX;
            string temp = "";
            for(int j = index;j < n;j++){
                temp += s[j];
                if(isPallindrome(temp)){
                    minCost = min(minCost, 1 + dp[j+1]);
                }
            }
            dp[index] = minCost;
        }
        return dp[0] - 1;
    }
};