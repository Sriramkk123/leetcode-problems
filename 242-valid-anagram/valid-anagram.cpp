class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> sMap(26,0);
        vector<int> tMap(26,0);
        for(int i = 0;i < s.size();i++){
            sMap[s[i] - 'a']++;
            tMap[t[i] - 'a']++;
        }

        for(int i = 0;i < 26;i++){
            if(sMap[i] != tMap[i]){
                return false;
            } 
        }
        return true;
    }
};