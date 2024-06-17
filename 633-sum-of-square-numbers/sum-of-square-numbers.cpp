class Solution {
private:
    bool binary_search(long low, long high, int res){
        while(low <= high){
            long mid = low + (high - low)/2;
            if(mid*mid == res){
                return true;
            }

            if(mid*mid > res){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
public:
    bool judgeSquareSum(int c) {
        for(long a = 0;a * a <= c;a++){
            double b = c - int(a*a);
            if(binary_search(0, b, b)){
                return true;
            }
        }
        return false;
    }
};