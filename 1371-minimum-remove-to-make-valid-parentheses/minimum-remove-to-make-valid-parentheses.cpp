class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        stack<int> st;
        for(int i = 0; i < s.size();i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            } else if(ch == ')'){
                if(!st.empty()){
                    st.pop();
                } else {
                    s[i] = '#';
                }
            }
        }

        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        for(int i = 0;i < s.size();i++){
            if(s[i] != '#'){
                res += s[i];
            }
        }
        return res;
    }
};