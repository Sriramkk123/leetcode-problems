class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> buckets(nums.size() + maxi, 0);
        for(int i = 0; i < nums.size();i++){
            buckets[nums[i]]++;
        }
        for(int i = 0;i < buckets.size() - 1;i++){
            if(buckets[i] > 1){
                int extra = buckets[i] - 1;
                buckets[i + 1] += extra;
                moves += extra;
            }
        }
        return moves;
    }
};
