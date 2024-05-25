class Solution {
private:
    string buildRes(vector<string>& current){
        string res = "";
        for(auto str : current){
            res += str + " ";
        }
        if(!res.empty()){
            res.pop_back();
        }
        return res;
    }
    void wordBreakHelper(int index, string s, vector<string>& current, 
                unordered_set<string>& wordSet, vector<string>& res){
        if(index == s.size()){
            res.push_back(buildRes(current));
        }

        for(int i = index;i < s.size();i++){
            string curr = s.substr(index, i - index + 1);
            if(wordSet.find(curr) != wordSet.end()){
                current.push_back(curr);
                wordBreakHelper(i + 1, s, current, wordSet, res);
                current.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> current;
        wordBreakHelper(0, s, current, wordSet, res);
        return res;
    }
};