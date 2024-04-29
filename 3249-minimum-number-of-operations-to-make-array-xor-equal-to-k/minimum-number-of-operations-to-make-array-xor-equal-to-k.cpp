class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr = 0;
        for(auto ele : nums){
            xorr = xorr ^ ele;
        }

        int res = 0;
        for(int i = 0;i < 32;i++){
            if((k & (1 << i)) != (xorr & (1 << i))){
                res++;
            }
        }
        return res;
    }
};