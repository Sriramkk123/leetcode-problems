class Solution {
public:
    int minimumDeletions(string s) {
        int minDeletions = 0;
        int bCount = 0;
        int n = s.size();
        for(auto ch : s){
            if(ch == 'b'){
                bCount++;
            } else {
                minDeletions = min(minDeletions + 1, bCount);
            }
        }
        return minDeletions;
    }
};