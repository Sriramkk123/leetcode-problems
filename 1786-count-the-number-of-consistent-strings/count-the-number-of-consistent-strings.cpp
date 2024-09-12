class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet;
        for(auto ch : allowed){
            allowedSet.insert(ch);
        }

        int res = 0;
        for(auto word : words){
            bool valid = true;
            for(auto ch : word){
                if(allowedSet.find(ch) == allowedSet.end()){
                    valid = false;
                    break;
                }
            }
            if(valid){
                res++;
            }
        }
        return res;
    }
};