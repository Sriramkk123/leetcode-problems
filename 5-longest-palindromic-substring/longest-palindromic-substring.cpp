class Solution {
public:
    string longestPalindrome(string s) {
        string maxi = s.substr(0, 1);
        int maxLen = 1;
        int n = s.size();
        for(int i = 0;i < n;i++){
            int left = i;
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                left--;
                right++;
            }

            if(right - left - 1 > maxLen){
                maxi = s.substr(left + 1, right - left - 1);
                maxLen = right - left - 1;
            }

            left = i;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                left--;
                right++;
            }

            if(right - left - 1 > maxLen){
                maxi = s.substr(left + 1, right - left - 1);
                maxLen = right - left - 1;
            }
        }
        return maxi;
    }
};