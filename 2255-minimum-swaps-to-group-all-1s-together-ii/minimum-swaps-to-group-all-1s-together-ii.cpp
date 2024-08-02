class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int swaps = 0;
        int n = nums.size();
        int right = 0;
        int left = 0;
        int totalOnes = 0;
        int maxWindowOnes = 0;
        int currentWindowOnes = 0;
        for(auto ele : nums){
            totalOnes += ele == 1 ? 1 : 0;
        }
        while(right < 2 * n){
            if(nums[right%n] == 1){
                currentWindowOnes++;
            }

            if(right - left + 1 > totalOnes){
                currentWindowOnes -= nums[left%n] == 1 ? 1 : 0;
                left++;
            }
            maxWindowOnes = max(maxWindowOnes, currentWindowOnes);  
            right++;
        }
        return totalOnes - maxWindowOnes;
    }
};