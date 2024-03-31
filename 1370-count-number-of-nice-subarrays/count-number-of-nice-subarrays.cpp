class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return niceSubArray(nums, k) - niceSubArray(nums, k-1);
    }
    int niceSubArray(vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;
        while(right < nums.size()){
            sum += (nums[right]%2);
            while(sum > goal){
                sum -= (nums[left]%2);
                left++;
            }

            if(sum <= goal){
                count += (right - left + 1);
            }
            right++;
        }
        return count;
    }
};