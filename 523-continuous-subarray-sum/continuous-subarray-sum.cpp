class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMod;
        int preSum = 0;
        prefixMod[0] = 0;
        for(int i = 0;i < nums.size();i++){
            preSum = (preSum + nums[i])%k;
            if(prefixMod.find(preSum) != prefixMod.end()){
                if(i + 1 - prefixMod[preSum] >= 2){
                    return true;
                }
            } else {
                prefixMod[preSum] = i + 1;
            }
        }
        return false;
    }
};

// 23 25 31 35 42