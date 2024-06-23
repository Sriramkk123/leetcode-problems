class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;
        int maxLen = 1;
        deque<pair<int,int>> maxD, minD;
        while(right < nums.size()){
            while(!maxD.empty() && maxD.back().first < nums[right]){
                maxD.pop_back();
            }
            maxD.push_back({nums[right], right});
            while(!minD.empty() && minD.back().first > nums[right]){
                minD.pop_back();
            }
            minD.push_back({nums[right], right});
            int diff = maxD.front().first - minD.front().first;
            while(left < right && diff > limit){
                left = min(maxD.front().second, minD.front().second) + 1;
                while(!maxD.empty() && maxD.front().second < left){
                    maxD.pop_front();
                }
                while(!minD.empty() && minD.front().second < left){
                    minD.pop_front();
                }
                diff = maxD.front().first - minD.front().first;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};