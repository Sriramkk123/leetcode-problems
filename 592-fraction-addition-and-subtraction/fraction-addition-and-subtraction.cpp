class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 1;

        int i = 0;
        while (i < expression.size()) {
            int currNum = 0;
            int currDenom = 0;

            bool isNegative = false;

            if (expression[i] == '-' || expression[i] == '+') {
                if (expression[i] == '-') {
                    isNegative = true;
                }
                i++;
            }

            while (isdigit(expression[i])) {
                int val = expression[i] - '0';
                currNum = currNum * 10 + val;
                i++;
            }

            if (isNegative) currNum *= -1;

            i++;

            while (i < expression.size() && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDenom = currDenom * 10 + val;
                i++;
            }

            numerator = numerator * currDenom + currNum * denominator;
            denominator = denominator * currDenom;
        }

        int hcf = abs(gcd(numerator, denominator));
        numerator /= hcf;
        denominator /= hcf;

        return to_string(numerator) + "/" + to_string(denominator);
    }

private:
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};