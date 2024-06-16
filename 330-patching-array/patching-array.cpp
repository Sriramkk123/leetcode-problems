class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long missing = 1;
        int i = 0;
        int added = 0;
        while(missing <= n){
            if(i < nums.size() && nums[i] <= missing){
                missing += nums[i];
                i++;
            } else {
                missing += missing;
                added++;
            }
        }
        return added;
    }
};