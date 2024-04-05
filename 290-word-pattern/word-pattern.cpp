class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        string word;
        vector<string> words;

        for (string word; ss >> word;) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) {
            return false;
        }

        unordered_map<char, string> patternMap;
        unordered_map<string, char> vectorMap;
        for (int i = 0; i < pattern.size(); i++) {
            if (patternMap.find(pattern[i]) == patternMap.end() &&
                vectorMap.find(words[i]) == vectorMap.end()) {
                patternMap[pattern[i]] = words[i];
                vectorMap[words[i]] = pattern[i];
            } else {
                if (patternMap[pattern[i]] != words[i] ||
                    vectorMap[words[i]] != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};