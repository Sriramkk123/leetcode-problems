class Solution {
private:
    int minStepsHelper(int i, int pasteLen, int n){
        if(i == n){
            return 0;
        }

        if(i > n) {
            return 1000;
        }

        int opt1 = 2 + minStepsHelper(i * 2, i, n);
        int opt2 = 1 + minStepsHelper(i + pasteLen, pasteLen, n);

        return min(opt1, opt2);
    }
public:
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        return 1 + minStepsHelper(1, 1, n);
    }
};