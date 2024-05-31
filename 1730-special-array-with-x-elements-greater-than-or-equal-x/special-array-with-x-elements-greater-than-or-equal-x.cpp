class Solution {
public:
    int specialArray(vector<int>& nums) {
        int total_right = 0;
        vector<int> count(nums.size() + 1, 0);
        for(auto ele : nums){
            if(ele > nums.size()){
                count[nums.size()]++;
            } else {
                count[ele]++;
            }
        }

        for(int i = nums.size();i >= 0;i--){
            total_right += count[i];
            if(i == total_right){
                return i;
            }
        }
        return -1;
    }
};