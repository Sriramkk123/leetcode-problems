class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;
        int maxLen = 1;
        deque<int> maxD, minD;
        while(right < nums.size()){
            while(!maxD.empty() && maxD.back() < nums[right]){
                maxD.pop_back();
            }
            maxD.push_back(nums[right]);
            while(!minD.empty() && minD.back() > nums[right]){
                minD.pop_back();
            }
            minD.push_back(nums[right]);
            int diff = maxD.front() - minD.front();
            while(left < right && diff > limit){
                if(nums[left] == maxD.front()){
                    maxD.pop_front();
                }
                if(nums[left] == minD.front()){
                    minD.pop_front();
                }
                diff = maxD.front() - minD.front();
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};