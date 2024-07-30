class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int res = 0;
        for(auto ch : s){
            if(st.empty()){
                st.push(ch);
            } else {
                if(ch == 'a' && st.top() == 'b'){
                    res++;
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }
        return res;
    }
};