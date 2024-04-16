class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int sign = 1;
        stack<pair<int,int>> st;
        for(int i = 0;i < s.size();i++){
            char current = s[i];
            if(isdigit(current)){
                int num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = num*10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num*sign;
                sign=1;
            } else if(current == '('){
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            } else if(current == '-'){
                sign = -1*sign;
            } else if(current == ')'){
                sum = st.top().first + st.top().second*sum;
                st.pop();
            }
        }
        return sum;
    }
};
