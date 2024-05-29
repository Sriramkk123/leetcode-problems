class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = (start + end)/2;
            int element = nums[mid];
            if(element == target){
                return mid;
            }

            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target <= element){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if(target >= element && target <= nums[end]){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

// 4 5 6 7 0 1 2 