class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(auto detail : details){
            int tensPlace = detail[11] - '0';
            int onesPlace = detail[12] - '0';
            int age = tensPlace*10 + onesPlace;
            if(age > 60){
                res++;
            }
        }
        return res;
    }
};