class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int temp = x;
        unsigned int rev = 0;
        while(temp){
            int rem = temp%10;
            rev = rev*10 + rem;
            temp /= 10;
        }
        if(x == rev){
            return true;
        }
        return false;
    }
};