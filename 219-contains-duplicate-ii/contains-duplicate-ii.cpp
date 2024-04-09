class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        for(int i = 0;i < nums.size();i++){
            if(mapp.find(nums[i]) == mapp.end()){
                mapp[nums[i]] = i;
            } else {
                int diff = abs(i - mapp[nums[i]]);
                mapp[nums[i]] = i;
                if(diff <= k){
                    return true;
                }
            }
        }
        return false;
    }
};