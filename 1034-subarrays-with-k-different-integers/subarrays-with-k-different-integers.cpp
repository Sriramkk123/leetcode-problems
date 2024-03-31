class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums, k - 1);
    }

    int solve(vector<int>& nums, int k){
        if(k < 0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int,int> cont;
        while(right < nums.size()){
            cont[nums[right]]++;
            while(cont.size() > k){
               cont[nums[left]]--;
               if(cont[nums[left]] == 0){
                cont.erase(nums[left]);
               }
               left++;
            }

            count += (right - left + 1);
            right++;
        }
        return count;
    }
};