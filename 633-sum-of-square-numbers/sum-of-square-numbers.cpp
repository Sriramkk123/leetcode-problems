class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<long long> cont;
        for(long a = 0;a * a <= c;a++){
            cont.insert((long)a*a);
            if(cont.find((long)(c - a*a)) != cont.end()){
                return true;
            }
        }
        return false;
    }
};