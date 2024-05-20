class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for(auto ele : nums){
            res |= ele;
        }
        return (res << nums.size() - 1);
    }
};