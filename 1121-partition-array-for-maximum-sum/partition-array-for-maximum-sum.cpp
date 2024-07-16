class Solution {
private:
    int maxSumAfterPartitioningHelper(int index, int n, vector<int>& arr, int k, vector<int>& dp){
        if(index == n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int len = 0;
        int maxAns = INT_MIN;
        int maxi = INT_MIN;
        for(int j = index;j < min(index + k, n);j++){
            len++;
            maxi = max(maxi, arr[j]);
            int res = maxi*len + maxSumAfterPartitioningHelper(j + 1, n, arr, k, dp);
            maxAns = max(maxAns, res);
        }
        return dp[index] = maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return maxSumAfterPartitioningHelper(0, arr.size(), arr, k, dp);
    }
};