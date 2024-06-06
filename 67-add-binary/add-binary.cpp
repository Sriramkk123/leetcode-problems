class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 || j >= 0){
            int as = i < 0 ? 0 : a[i] - '0';
            int bs = j < 0 ? 0 : b[j] - '0';
            int total = as + bs + carry;

            int r = total%2;
            res += to_string(r);

            carry = total/2;
            i--;
            j--;
        }
        if(carry > 0){
            res += to_string(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};