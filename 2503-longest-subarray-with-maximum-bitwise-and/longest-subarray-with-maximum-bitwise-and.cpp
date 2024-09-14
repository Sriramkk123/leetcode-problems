class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int consecutive = 0;
        int res = 0;
        for(auto ele : nums){
            if(ele > maxi){
                maxi = ele;
                res = 0;
                consecutive = 0;
            }

            if(ele == maxi){
                consecutive++;
            } else {
                consecutive = 0;
            }

            res = max(res, consecutive);
        }
        return res;
    }
};