class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        unordered_map<char,char> match;
        match[')'] = '(';
        match['}'] = '{';
        match[']'] = '[';
        string open = "({[";
        string closed = ")}]";
        for(auto item : s){
            if(open.find(item) != string::npos){
                parentheses.push(item);
            } else if(closed.find(item) != string::npos){
                if(parentheses.size() == 0){
                    return false;
                }

                if(parentheses.top() == match[item]){
                    parentheses.pop();
                } else {
                    return false;
                }
            }
        }
        return parentheses.size() == 0; 
    }
};