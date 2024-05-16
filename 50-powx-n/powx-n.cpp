class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long temp = (long long)n;
        if(n < 0){
            temp = (long long)-1*n;
        }

        while(temp > 0){
            if(temp & 1){
                res = res * x;
                temp -= 1;
            } else {
                x = x * x;
                temp /= 2;
            }
        }

        if(n < 0){
            return (double)1/res;
        }

        return res;
    }
};