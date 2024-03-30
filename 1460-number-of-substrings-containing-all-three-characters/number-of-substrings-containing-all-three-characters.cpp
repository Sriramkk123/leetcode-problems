class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<int> hash{ -1, -1, -1};
        for(int i = 0;i < s.size();i++){
            hash[s[i] - 'a'] = i;
            if(hash[0] != -1 &&  hash[1] != -1 && hash[2] != -1){
                count += (1 + min(hash[0], min(hash[1], hash[2])));
            }
        }
        return count;
    }
};