class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = accumulate(nums.begin(), nums.end(), 0LL);
        vector<int> deltaNums(nums.size(), 0);
        for(int i = 0;i < nums.size();i++){
            int xored = nums[i]^k;
            deltaNums[i] = xored - nums[i];
        }

        sort(deltaNums.begin(), deltaNums.end(), [](int a, int b){
            return a > b;            
        });
        int i = 0;
        while(i < deltaNums.size()){
            if(i == deltaNums.size() - 1){
                break;
            }

            long long curr_total = (long long)deltaNums[i] + deltaNums[i+1];
            if(curr_total < 0){
                break;
            }
            res += (long long)curr_total;
            i+=2;
        }
        return res;
    }
};