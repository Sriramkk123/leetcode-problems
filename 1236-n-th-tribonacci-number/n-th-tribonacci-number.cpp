class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1){
            return n;
        }
        if(n == 2){
            return 1;
        }
        int prevToPrevToPrev = 0;
        int prevToPrev = 1;
        int prev = 1;
        int result;
        for(int i = 3;i <= n;i++){
            result = prev + prevToPrev + prevToPrevToPrev;
            prevToPrevToPrev = prevToPrev;
            prevToPrev = prev;
            prev = result;
        }
        return result;
    }
};