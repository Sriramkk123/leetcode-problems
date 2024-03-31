class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxFreq = 0;
        while(right < s.size()){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            if((right - left + 1) - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, (right - left + 1));
            right++;
        }
        return maxLen;
    }
};