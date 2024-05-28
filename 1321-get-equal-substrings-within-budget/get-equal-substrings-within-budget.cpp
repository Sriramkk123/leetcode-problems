class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = INT_MIN;
        int left = 0;
        int right = 0;
        int cost = 0;
        while(right < s.size()){
            cost += abs((s[right] - 'a') - (t[right] - 'a'));

            if(cost > maxCost){
                while(cost > maxCost){
                    cost -= abs((s[left] - 'a') - (t[left] - 'a'));
                    left++;
                }
            }

            length = max(length, right - left + 1);
            right++;
        }
        return length;
    }
};