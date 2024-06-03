class Solution {
private:
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(first == nums.size() || nums[first] != target){
            return vector<int>{-1,-1};
        }
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return vector<int>{first, last - 1};
    }
};