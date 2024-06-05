class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto ele : nums){
            res ^= ele;
        }
        return res;
    }
};