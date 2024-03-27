class Solution {
public:
    bool isAlphaNumberic(char c){
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'); 
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            while(i < j && !isAlphaNumberic(s[i])){
                i++;
            }

            while(i < j && !isAlphaNumberic(s[j])){
                j--;
            }

            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};