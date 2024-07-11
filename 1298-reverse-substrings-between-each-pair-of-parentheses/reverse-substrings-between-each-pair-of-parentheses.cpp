class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<char> st;
        for(auto cha : s){
            if(cha == '(' || cha >= 'a' && cha <= 'z'){
                st.push(cha);
            } else {
                string temp = "";
                while(st.top() != '('){
                    char item = st.top();
                    temp += item;
                    st.pop();
                }
                st.pop();
                for(char ch : temp){
                    st.push(ch);
                }
            }
        }
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};