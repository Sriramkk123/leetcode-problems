class Solution {
private:
    vector<string> splitBySpace(string sentence){
        vector<string> res;
        string temp = "";
        int i = 0;
        int size = sentence.size();

        while(i < size){
            if(sentence[i] == ' '){
                res.push_back(temp);
                temp = "";
                i++;
            } else { 
                temp += sentence[i];
                i++;
            }
        }
        if(temp != " ") {
            res.push_back(temp);
        }
        return res;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;
        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
        vector<string> sentenceList = splitBySpace(sentence);
        for(auto val : sentenceList){
            string word = val;
            int i = 0;
            for(;i < word.size();i++){
                string sub = word.substr(0, i+1);
                if(wordSet.count(sub) >= 1){
                    res += sub + " ";
                    break;
                }
            }
            if(i == word.size()){
                res += word + " ";
            }
        }
        if(!res.empty()){
            res.pop_back();
        }
        return res;
    }
};