class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> st;
        unordered_map<int,int> paranthesisPairs;
        for(int i = 0;i < s.size();i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            } else if(ch == ')'){
                int top = st.top();
                paranthesisPairs[i] = top;
                paranthesisPairs[top] = i;
                st.pop();
            }
        }
        int direction = 1;
        int i = 0;
        while(i < s.size()){
            if(s[i] == '(' || s[i] == ')'){
                i = paranthesisPairs[i];
                direction = -direction;
            } else {
                res += s[i];
            }
            i += direction;
        }
        return res;
    }
};