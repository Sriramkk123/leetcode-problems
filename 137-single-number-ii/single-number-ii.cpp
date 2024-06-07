class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 31;i >=0;i--){
            int setBits = 0;
            for(int j = 0;j < nums.size();j++){
                if(nums[j] & (1 << i)){
                    setBits++;
                }
            }
            if(setBits%3 == 1){
                res = res | (1 << i);
            }
        }
        return res;
    }
};