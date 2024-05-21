class Solution {
private:
    void helper(int index, vector<int> currentSubset, vector<int>& nums, vector<vector<int>>& subsets){
        if(index == nums.size()){
            subsets.push_back(currentSubset);
            return;
        }

        helper(index + 1, currentSubset, nums, subsets);
        currentSubset.push_back(nums[index]);
        helper(index + 1, currentSubset, nums, subsets);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> cSubset;
        helper(0, cSubset, nums, subsets);
        return subsets;
    }
};