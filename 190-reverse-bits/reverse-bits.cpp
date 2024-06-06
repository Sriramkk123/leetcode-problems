class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string res;
        for(int i = 31;i >= 0;i--){
            if(n&(1<<i)){
                res += (to_string(1));
            } else {
                res += (to_string(0));
            }
        }
        reverse(res.begin(), res.end());
        uint32_t ans = 0;
        for(int i = 31;i >= 0;i--){
            int bit = res[i] - '0';
            if(bit){
                ans += (1<<(31 - i));
            }
        }
        return ans;
    }
};