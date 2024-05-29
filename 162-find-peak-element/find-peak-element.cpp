class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            int element = nums[mid];

            long  left = LONG_MIN;
            long right = LONG_MIN;

            if(mid - 1 >= 0){
                left = nums[mid - 1];
            }

            if(mid + 1 <= n-1){
                right = nums[mid + 1];
            }

            if(element > left && element > right){
                return mid;
            }

            if(element > left){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};