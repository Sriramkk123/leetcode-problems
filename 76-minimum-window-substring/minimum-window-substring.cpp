class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int startIndex = -1;
        int count = 0;
        unordered_map<char, int> cont;
        for(auto ele : t){
            cont[ele]++;
        } 

        while(right < s.size()){
            if(cont[s[right]] > 0){
                count++;
            }
            cont[s[right]]--;

            while(count == t.size()){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    startIndex = left;
                }

                cont[s[left]]++;
                if(cont[s[left]] > 0){
                    count--;
                }
                left++;
            }
            right++;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};