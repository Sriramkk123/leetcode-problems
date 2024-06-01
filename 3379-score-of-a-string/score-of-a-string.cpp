class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        int i = 1;
        while(i < s.size()){
            score += abs((s[i] - 'a') - (s[i-1] - 'a'));
            i++;
        }
        return score;
    }
};