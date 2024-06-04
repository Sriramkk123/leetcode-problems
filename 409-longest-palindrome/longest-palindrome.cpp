class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> cont;
        int res = 0;
        for(auto ele : s){
            if(cont.count(ele) > 0){
                res += 2;
                cont.erase(ele);
            } else {
                cont.insert(ele);
            }
        }

        if(!cont.empty()){
            res++;
        }
        return res;
    }
};