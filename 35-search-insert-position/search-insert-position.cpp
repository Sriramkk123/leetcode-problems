class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0;
        int ans = 0;
        int last = nums.size() - 1;
        int mid;
        while(first <= last){
            mid = first + (last-first)/2;
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[mid] > target){
                last = mid - 1;
            }else{
                ans = mid + 1;
                first = mid + 1;
            }
        }
        return first;
    }
};

// 1 3 5 6