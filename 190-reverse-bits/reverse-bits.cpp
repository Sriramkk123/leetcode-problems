class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0){
            return 0;
        }
        int ans = 0;
        for(int i = 0;i < 32;i++){
            int bit = (n >> i)&1;
            ans = ans | (bit << (31 - i));
        }
        return ans;
    }
};