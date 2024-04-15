class Solution {
private:
    int compute(int one, string op, int two){
        if(op == "+"){
            return one + two;
        }

        if(op == "-"){
            return one - two;
        }

        if(op == "*"){
            return one * two;
        }

        return one / two;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(auto token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();
                numbers.push(compute(first, token, second));
            } else {
                int number = stoi(token);
                numbers.push(number);
            }
        }
        return numbers.top();
    }
};