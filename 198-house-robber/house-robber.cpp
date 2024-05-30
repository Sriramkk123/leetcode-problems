class Solution {
public:
    int rob(vector<int>& nums) {
        int robPrevious = 0;
        int robPreviousToPrevious = 0;
        for(int i = 0;i < nums.size();i++){
            int current = max(nums[i] + robPreviousToPrevious, robPrevious);
            robPreviousToPrevious = robPrevious;
            robPrevious = current;
        }
        return robPrevious;
    }
};