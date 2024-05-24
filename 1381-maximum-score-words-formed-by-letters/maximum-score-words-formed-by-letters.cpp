class Solution {
private:
    bool isValid(unordered_map<char, int>& freq, string word){
        unordered_map<char, int> cwMap;
        for(auto str : word){
            cwMap[str]++;
        }

        for(auto ele : word){
            cout<<ele<<" ";
            if(freq.find(ele) == freq.end()){
                return false;
            }
            if(cwMap[ele] > freq[ele]){
                return false;
            }
        }
        return true;
    }
    int getScore(string word, vector<int>& score){
        int scor = 0;
        for(auto ele : word){
            scor += score[ele - 'a'];
        }
        cout<<scor<<"\n";
        return scor;
    }
    int helper(int index, vector<string>& words, vector<char>& letters, vector<int>& score, unordered_map<char, int>& freq){
        if(index == words.size()){
            return 0;
        }
        int res = helper(index + 1, words, letters, score, freq);
        if(isValid(freq, words[index])){
            for(auto ele : words[index]){
                freq[ele]--;
            }
            res = max(res, getScore(words[index], score) + helper(index + 1, words, letters, score, freq));
            for(auto ele : words[index]){
                freq[ele]++;
            }
        }
        return res;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> freq;
        for(int i = 0;i < letters.size();i++){
            freq[letters[i]]++;
        }

        return helper(0, words, letters, score, freq);
    }
};