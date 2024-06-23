class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;
        int maxLen = 1;
        multiset<int> mt;
        while(right < nums.size()){
            mt.insert(nums[right]);
            int diff = *mt.rbegin() - *mt.begin();
            while(left < right && diff > limit){
                auto toRemove = mt.find(nums[left]);
                mt.erase(toRemove);
                left++;
                diff = *mt.rbegin() - *mt.begin();
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};