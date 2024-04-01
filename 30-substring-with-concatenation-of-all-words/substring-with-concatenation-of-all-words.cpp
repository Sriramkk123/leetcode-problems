class Solution {
public:
    bool isValid(string s, unordered_map<string, int> wordContainer, int singleWordSize){
        for(int j = 0;j < s.size(); j+= singleWordSize){
            string currentSubstring = s.substr(j,singleWordSize);
            if(wordContainer.find(currentSubstring) != wordContainer.end()){
                wordContainer[currentSubstring]--;
                if(wordContainer[currentSubstring] < 0){
                    return false;
                }
            }else {
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size();
        int singleWordSize = words[0].size();
        int totalWordsSize = singleWordSize*words.size();
        
        unordered_map<string, int> wordContainer;
        for(auto word : words){
            wordContainer[word]++;
        }

        int i = 0;
        while(i + totalWordsSize <= n){
            if(isValid(s.substr(i, totalWordsSize), wordContainer, singleWordSize)){
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};