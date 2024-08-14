class Solution {
private:
    int countPairs(vector<int>& nums, int diff){
        int left = 0;
        int right = 0;
        int count = 0;
        while(right < nums.size()){
            while(nums[right] - nums[left] > diff){
                left++;
            }

            count += (right - left);
            right++;
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[n-1] - nums[0];
        while(low < high){
            int mid = (low + high)/2;
            int noOfPairs = countPairs(nums, mid);
            if(noOfPairs >= k){
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};