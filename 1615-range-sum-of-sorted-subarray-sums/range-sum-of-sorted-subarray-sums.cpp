class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sumSubArray;
        for(int i = 0;i < n;i++){
            int sum = 0;
            for(int j = i;j < n;j++){
                sum += nums[j];
                sumSubArray.push_back(sum);
            }
        }
        sort(sumSubArray.begin(), sumSubArray.end());
        int sum = 0;
        int mod = 1e9+7;
        for(int i = left - 1;i < right;i++){
            sum = (sum + sumSubArray[i])%mod; 
        }
        return sum;
    }
};