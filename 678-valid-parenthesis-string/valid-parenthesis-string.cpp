class Solution {
public:
    bool checkValidString(string s) {
        int openMin = 0;
        int openMax = 0;
        for(auto item : s){
            if(item == '('){
                openMin++;
                openMax++;
            } else if(item == '*'){
                openMin--;
                openMax++;
            } else if(item == ')'){
                openMin--;
                openMax--;
                if(openMax < 0){
                    return false;
                }
            }

            if(openMin < 0){
                openMin = 0;
            }
        }
        return openMin == 0;
    }
};