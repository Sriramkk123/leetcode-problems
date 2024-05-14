class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(int ele : nums){
            sum += ele;
            maxSum = max(maxSum, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = maxSubArray(nums);
        int total = 0;
        for(int i = 0;i < nums.size();i++){
            total += nums[i];
            nums[i] = -1*nums[i];
        }

        int circularSum = total + maxSubArray(nums);
        if(circularSum == 0){
            return maxSum;
        }

        return max(maxSum, circularSum);
    }
};