class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = INT_MIN;
        for(int i = 0;i < s.size();i++){
            int currentCost = 0;
            int maxLength = 0;
            for(int j = i;j < s.size();j++){
                int cst = abs((s[j] - 'a') - (t[j] - 'a'));
                if(currentCost + cst <= maxCost){
                    currentCost += cst; 
                    maxLength++;
                } else {
                    break;
                }
            }
            length = max(length, maxLength);
        }
        return length;
    }
};
// 6 + 12