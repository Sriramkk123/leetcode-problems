class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string,int> count;
        istringstream iss(s1 + " " + s2);
        while (iss >> s1) 
            count[s1]++;
        for (auto w: count)
            if (w.second == 1)
                res.push_back(w.first);
        return res;
    }
};