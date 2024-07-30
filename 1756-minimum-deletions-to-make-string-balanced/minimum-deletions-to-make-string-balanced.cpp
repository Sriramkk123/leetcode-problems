class Solution {
public:
    int minimumDeletions(string s) {
        int res = s.size();
        int aCountRight = 0;
        for(auto ch : s){
            if(ch == 'a'){
                aCountRight++;
            }
        }
        int bCountLeft = 0;
        for(auto ch : s){
            if(ch == 'a'){
                aCountRight--;
            }
            res = min(res, aCountRight + bCountLeft);
            if(ch == 'b'){
                bCountLeft++;
            }
        }
        return res;
    }
};