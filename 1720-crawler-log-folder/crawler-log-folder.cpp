class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> st;
        for(auto log : logs){
            if(log == "../"){
                if(!st.empty()){
                    st.pop_back();
                }
                continue;
            }

            if(log == "./"){
                continue;
            } 
            st.push_back(log);
        }
        return st.size();
    }
};