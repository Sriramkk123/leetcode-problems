class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1;i < nums.size(); i += 3){
            if(nums[i-1] != nums[i] || nums[i+1] != nums[i]){
                return nums[i - 1];
            }
        }
        return nums[nums.size() - 1];
    }
};

// 100 100 100 500 30000 30000 30000
// 1 1 1 2 3 3 3