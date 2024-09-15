class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res = 0;
        unordered_map<char,int> maskMap;
        maskMap['a'] = 1;
        maskMap['e'] = 2;
        maskMap['i'] = 4;
        maskMap['o'] = 8;
        maskMap['u'] = 16;
        int prefixXor = 0;
        vector<int> mp(32, -1);
        for(int i = 0;i < s.size();i++){
            char ch = s[i];
            prefixXor ^= maskMap[ch];

            if(mp[prefixXor] == -1 && prefixXor != 0){
                mp[prefixXor] = i;
            }

            res = max(res, i - mp[prefixXor]);
        }
        return res;
    }
};