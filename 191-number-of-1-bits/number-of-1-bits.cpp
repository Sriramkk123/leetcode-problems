class Solution {
public:
    int hammingWeight(int n) {
        int temp = n;
        int res = 0;
        while(temp > 0){
            res++;
            temp = temp & temp-1;
        }
        return res;
    }
};