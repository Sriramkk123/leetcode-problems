class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long runningSum = 0LL;
        int ways = 0;
        for(int i = 0;i < nums.size() - 1;i++){
            runningSum += nums[i];
            sum -= nums[i];
            if(runningSum >= sum){
                ways++;
            }
        }
        return ways;
    }
};