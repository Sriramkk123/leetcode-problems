class Solution {
private:
    string addOne(string s){
        int i = s.size() - 1;
        while(i >= 0 && s[i] == '1'){
            s[i] = '0';
            i--;
        }
        if(i >= 0){
            s[i] = '1';
        } else {
            s = '1' + s;
        }
        return s;
    }
public:
    int numSteps(string s) {
        int steps = 0;
        while(s != "1"){
            int n = s.size() - 1;
            if(s[n] == '0'){
                s = s.substr(0, n);
            } else {
                s = addOne(s);
            }
            steps++;
        }
        return steps;
    }
};