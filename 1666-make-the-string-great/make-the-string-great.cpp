class Solution {
public:
    string makeGood(string s) {
        string res;
        stack<char> st;
        for(int i = 0;i < s.size();i++){
            if(!st.empty() && abs(s[i] - st.top()) == 32){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};