class Solution {
public:
    void helper(int open, int close, int n, string& current, vector<string>& res){
        if(current.size() == n*2){
            res.push_back(current);
            return;
        }

        if(open < n){
            current += "(";
            helper(open+1, close, n, current, res);
            current.pop_back();
        }

        if(close < open){
            current += ")";
            helper(open, close + 1, n, current, res);
            current.pop_back(); 
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current = "";
        helper(0, 0, n, current, res);
        return res;
    }
};