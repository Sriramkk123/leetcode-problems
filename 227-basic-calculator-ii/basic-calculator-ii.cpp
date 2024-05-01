class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> st;
        char sign = '+';
        long long num = 0;
        string operations="+-*/";
        for(int i = 0;i < s.size();i++){
            char ch = s[i];
            if(isdigit(ch)){
                num = num*10 + (ch - '0');
            }  
            
            if(operations.find(ch) != string::npos || i == s.size() - 1){
                if(sign == '+'){
                    st.push(num);
                } else if(sign == '-'){
                    st.push(-1*num);
                } else if(sign == '*'){
                    int currTop = st.top();
                    st.pop();
                    st.push(num*currTop);
                } else if(sign == '/'){
                    int currTop = st.top();
                    st.pop();
                    st.push(currTop/num);
                }

                num = 0;
                sign = s[i];
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};