class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int emptyEligible = numBottles;
        while((emptyEligible/numExchange) > 0){
            int emptyElig = emptyEligible/numExchange;
            int remBottles = emptyEligible%numExchange;
            res += emptyElig;
            emptyEligible = emptyElig + remBottles;
        }
        return res;
    }
};