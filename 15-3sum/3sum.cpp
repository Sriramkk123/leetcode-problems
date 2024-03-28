class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> customRes;
        sort(nums.begin(), nums.end());
        int i = 0;
        for(;i < nums.size();i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int currSum = nums[i] + nums[j] + nums[k];
                if(currSum == 0){
                    customRes.insert(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if(currSum > 0){
                    k--;
                } else {
                    j++;
                }
            }
        }
        for(auto it : customRes){
            res.push_back(it);
        }
        return res;
    }
};