class Solution {
public:
    int findComplement(int num) {
        if(num == 0){
            return 1;
        } 

        long long res = 0;
        long long multiplier = 1;
        while(num) {
            if(num % 2 == 0) {
                res += multiplier;
            }

            num /= 2;
            multiplier *= 2;
        }

        return (int)res;
    }
};