class Solution {
public:
    void helper(int index, vector<int>& nums, int curr, int& sum){
        if(index == nums.size()){
            sum += curr;
            return;
        }

        helper(index + 1, nums, curr^nums[index], sum);
        helper(index + 1, nums, curr, sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int curr = 0;
        helper(0, nums, curr, sum);
        return sum;
    }
};