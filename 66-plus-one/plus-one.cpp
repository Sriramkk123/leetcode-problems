class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 0;
        for(int i = digits.size() - 1;i >= 0;i--){
            int result = digits[i];
            int total = result + carry;
            if(i == digits.size() - 1){
                total++;
            }
            res.push_back(total%10);
            carry = total/10;
        }
        if(carry > 0){
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};