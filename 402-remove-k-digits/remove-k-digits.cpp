class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()){
            return "0";
        }

        string res = "";
        for(auto ch : num){
            while(res.length() > 0 && res.back() > ch && k > 0){
                k--;
                res.pop_back();
            }

            if(res.length() > 0 || ch != '0'){
                res.push_back(ch);
            }
        }

        while(res.length() > 0 && k > 0){
            k--;
            res.pop_back();
        }

        return res.empty() ? "0" : res; 
    }
};