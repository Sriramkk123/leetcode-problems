class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while(true){
            int pivot = start;
            int leftIdx = start + 1;
            int rightIdx = end;
            while(leftIdx <= rightIdx){
                if(nums[leftIdx] < nums[pivot] && nums[rightIdx] > nums[pivot]){
                    swap(nums[leftIdx], nums[rightIdx]);
                }
                if(nums[leftIdx] >= nums[pivot]){
                    leftIdx++;
                }
                if(nums[rightIdx] <= nums[pivot]){
                    rightIdx--;
                }
            }
            swap(nums[pivot], nums[rightIdx]);
            if(rightIdx == k-1){
                return nums[rightIdx];
            }
            if(rightIdx < k){
                start = rightIdx + 1;
            } else {
                end = rightIdx - 1;
            }
        }
        return -1;
    }
};