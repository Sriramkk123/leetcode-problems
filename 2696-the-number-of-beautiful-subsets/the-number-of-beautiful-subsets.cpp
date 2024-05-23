class Solution {
private:
    int helper(int index, unordered_map<int, int>& cont, vector<int>& nums, int k){
        if(index == nums.size()){
            return 1;
        }
        
        int res = helper(index + 1, cont, nums, k);
        if(!cont[nums[index] - k] && !cont[nums[index] + k]){
            cont[nums[index]]++;
            res += helper(index + 1, cont, nums, k);
            cont[nums[index]]--;
        }
        return res;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> cont;
        return helper(0, cont, nums, k) - 1;
    }
};