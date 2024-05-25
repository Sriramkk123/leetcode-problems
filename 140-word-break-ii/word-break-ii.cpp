class Solution {
private:
    void wordBreakHelper(int index, string s, string current, 
                unordered_set<string>& wordSet, vector<string>& res){
        if(index == s.size()){
            current.pop_back();
            res.push_back(current);
        }

        for(int i = index;i < s.size();i++){
            string curr = s.substr(index, i - index + 1);
            if(wordSet.find(curr) != wordSet.end()){
                string newToAdd = curr + " ";
                current += newToAdd;
                wordBreakHelper(i + 1, s, current, wordSet, res);
                for(int k = 0;k <= i - index + 1;k++){
                    current.pop_back();
                }
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> res;
        string current = "";
        wordBreakHelper(0, s, current, wordSet, res);
        return res;
    }
};