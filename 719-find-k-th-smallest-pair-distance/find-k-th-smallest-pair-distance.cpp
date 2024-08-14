class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> maxArray(maxElement + 1, 0);
        for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                maxArray[abs(nums[i] - nums[j])]++;
            }
        }

        for(int i = 0;i < maxArray.size();i++){
            k -= maxArray[i];
            if(k <= 0){
                return i;
            }
        }

        return -1;
    }
};