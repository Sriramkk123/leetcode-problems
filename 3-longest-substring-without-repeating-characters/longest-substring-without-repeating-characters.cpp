class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        vector<int> alreadySeenCharacters(255,-1);
        while(right < s.size()){
            if(alreadySeenCharacters[s[right]] != - 1 && alreadySeenCharacters[s[right]] >= left){
                left = alreadySeenCharacters[s[right]] + 1;
            } 
            maxLength = max(maxLength, right - left + 1);
            alreadySeenCharacters[s[right]] = right;
            right++;
        }
        return maxLength;
    }
};

