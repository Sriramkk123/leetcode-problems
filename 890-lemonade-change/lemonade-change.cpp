class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twenties = 0;
        for(int i = 0;i < bills.size();i++){
            if(bills[i] == 5){
                fives++;
                continue;
            }

            if(bills[i] == 10){
                if(fives == 0){
                    return false;
                } else {
                    tens++;
                    fives--;
                }
                continue;
            }

            if(bills[i] == 20){
                if(fives && tens){
                    tens--;
                    fives--;
                    twenties++;
                } else if(fives >= 3){
                    fives -= 3;
                    twenties++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};