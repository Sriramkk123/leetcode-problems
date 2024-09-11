class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        int diffResult = start ^ goal;
        while(diffResult > 0){
            diffResult = diffResult & (diffResult - 1);
            res++;
        }
        return res;
    }
};