class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return n;
        }

        if(n == 2){
            return n;
        }

        int prev = 2;
        int prevToPrev = 1;
        int res = 0;
        for(int i = 3; i <= n;i++){
            res = prev + prevToPrev;
            prevToPrev = prev;
            prev = res;
        }
        return res;
    }
};