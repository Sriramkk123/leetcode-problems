class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i - 1] + 1 == nums[i]) {
                    len++;
                    maxLen = max(len, maxLen);
                } else {
                    len = 1;
                }
            }
        }
        return maxLen;
    }
};

// 0 0 1 2 3 4 5 6 7