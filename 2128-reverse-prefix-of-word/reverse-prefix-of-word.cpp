class Solution {
public:
    void reverse(string& word, int startIndex, int endIndex){
        int start = startIndex;
        int end = endIndex;
        while(start < end){
            swap(word[start], word[end]);
            start++;
            end--;
        }
    }
    string reversePrefix(string word, char ch) {
        int chIndex = -1;
        for(int i = 0;i < word.size();i++){
            if(ch == word[i]){
                chIndex = i;
                break;
            }
        }
        if(chIndex == -1){
            return word;
        }
        reverse(word, 0, chIndex);
        return word;
    }
};