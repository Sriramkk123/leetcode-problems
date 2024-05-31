class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i = 0;i < nums.size();i++){
            xorr = xorr ^ nums[i];
        }

        int diffBit = 1;
        while(!(xorr & diffBit)){
            diffBit <<= 1;
        }
        int evenDiff = 0;
        int oddDiff = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i]&diffBit){
                oddDiff ^= nums[i];
            } else {
                evenDiff ^= nums[i];
            }
        }
        return {oddDiff, evenDiff};
    }
};
