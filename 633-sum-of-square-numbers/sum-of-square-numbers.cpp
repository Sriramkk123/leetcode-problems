class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        while(left <= right){
            long long target = left*left + right*right;
            if(target == c){
                return true;
            }

            if(target > c){
                right--;
            } else{
                left++;
            }
        }
        return false;
    }
};