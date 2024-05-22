class Solution {
private:
    bool isPallindrome(string s, int left, int right){
        if(s.empty()){
            return false;
        }

        while(left <= right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    void helper(int index, string s, vector<string>& current, vector<vector<string>>& res){
        if(index == s.size()){
            res.push_back({current});
            return;
        }
        for(int i = index;i < s.size();i++){
            if(isPallindrome(s, index, i)){
                current.push_back(s.substr(index, i - index + 1));
                helper(i + 1, s, current, res);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> res;
        helper(0, s, current, res);
        return res;
    }
};