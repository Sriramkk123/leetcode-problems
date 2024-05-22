class Solution {
private:
    void helper(int index, string& digits, string current,
                unordered_map<int, string>& numberMap, vector<string>& res){
        if(index == digits.size()){
            if(!current.empty()){
                res.push_back(current);
            }
            return;
        }

        string currentStr = numberMap[digits[index] - '0'];
        for(int i = 0;i < currentStr.size();i++){
            current += currentStr[i];
            helper(index + 1, digits, current, numberMap, res);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<int, string> numberMap;
        numberMap[0] = "";
        numberMap[1] = "";
        numberMap[2] = "abc";
        numberMap[3] = "def";
        numberMap[4] = "ghi";
        numberMap[5] = "jkl";
        numberMap[6] = "mno";
        numberMap[7] = "pqrs";
        numberMap[8] = "tuv";
        numberMap[9] = "wxyz";
        helper(0, digits, "", numberMap, res);
        return res;
    }
};