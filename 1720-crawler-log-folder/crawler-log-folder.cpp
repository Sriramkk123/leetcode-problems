class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto log : logs){
            if(log == "../"){
                if(!st.empty()){
                    st.pop();
                }
                continue;
            }

            if(log == "./"){
                continue;
            } 
            st.push(log);
        }
        return st.size();
    }
};