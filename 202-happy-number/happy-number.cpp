class Solution {
public:
    int sumOfSquaresOfDigits(int number){
        int res = 0;
        while(number > 0){
            int rem = number%10;
            res += rem*rem;
            number = number/10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSquaresOfDigits(n);
        while(fast != 1 && slow != fast) {
            slow = sumOfSquaresOfDigits(slow);
            fast = sumOfSquaresOfDigits(sumOfSquaresOfDigits(fast));
        } 
        return fast == 1;
    }
};