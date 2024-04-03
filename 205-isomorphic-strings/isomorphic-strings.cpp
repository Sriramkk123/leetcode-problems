class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> sMap(256,-1);
        vector<int> tMap(256,-1);
        for(int i = 0;i < s.size();i++){
            if(sMap[s[i]] != tMap[t[i]]){
                return false;
            }
            sMap[s[i]] = i + 1;
            tMap[t[i]] = i + 1;
        }
        return true;
    }
};