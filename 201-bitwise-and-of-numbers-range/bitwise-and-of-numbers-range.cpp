class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left){
            right = right&(right-1);
        }
        return right;
    }
};

// 7
// 111 & 110
// 110 & 101
// 101