class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        int start = 1;
        int end = INT_MAX;
        int res = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid == x/mid){
                return mid;
            }
            if(mid > x/mid){
                end = mid - 1;
            } else {
                res = mid;
                start = mid + 1;
            }
        }
        return res;
    }
};