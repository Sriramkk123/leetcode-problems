class Solution {
private:
    int maxSum(const vector<int>& prefixSum, int L, int M) {
        int result = 0;
        int maxL = 0;
        
        for (int i = L + M; i < prefixSum.size(); i++) {
            maxL = max(maxL, prefixSum[i - M] - prefixSum[i - L - M]);
            
            result = max(result, maxL + prefixSum[i] - prefixSum[i - M]);
        }
        
        return result;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        return max(maxSum(prefixSum, firstLen, secondLen),
                   maxSum(prefixSum, secondLen, firstLen));
    }
};
