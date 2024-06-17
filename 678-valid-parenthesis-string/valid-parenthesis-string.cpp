class Solution {
public:
    bool checkValidString(string s) {
        int openMin = 0;
        int openMax = 0;
        for(char ch : s){
            if(ch == '('){
                openMin++;
                openMax++;
            } else if(ch == ')'){
                openMin--;
                openMax--;
            } else if(ch == '*'){
                openMin--;
                openMax++;
            }

            if(openMin < 0){
                openMin = 0;
            }

            if(openMax < 0){
                return false;
            }
        }
        return openMin == 0;
    }
};