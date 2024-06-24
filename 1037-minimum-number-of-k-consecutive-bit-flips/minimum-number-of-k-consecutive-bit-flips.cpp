class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        int right = 0;
        int times = 0;
        while(right < n){
            if(right >= k && nums[right - k] == 2){
                times--;
            }

            if((nums[right] == 1 && times%2 == 1) || (nums[right] == 0 && times%2 == 0)){
                if(right + k > n){
                    return -1;
                }
                res++;
                nums[right] = 2;
                times++;
            }
            right++;
        }
        return res;
    }
};