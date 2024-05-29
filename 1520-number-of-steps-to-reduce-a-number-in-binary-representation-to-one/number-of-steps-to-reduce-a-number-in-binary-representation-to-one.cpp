class Solution {
private:
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        for(int i = s.size() - 1;i > 0;i--){
            int digit = (s[i] - '0' + carry)%2;
            if(digit == 0){
                steps++;
            } else {
                carry = 1;
                steps += 2;
            }
        }
        return steps + carry;
    }
};