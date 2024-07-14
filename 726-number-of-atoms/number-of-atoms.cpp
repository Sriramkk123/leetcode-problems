class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> container;
        container.push(map<string, int>());
        int i = 0;
        int n = formula.size();
        while(i < n){
            if(formula[i] == '('){
                container.push(map<string, int>());
                i++;
            } else if(formula[i] == ')'){
                auto currMap = container.top();
                container.pop();
                i++;
                string count = "";
                while(i < n && isdigit(formula[i])){
                    count += formula[i];
                    i++;
                }
                int cnt = count == "" ? 1 : stoi(count);
                for(auto& [ele, existingCount] : currMap){
                    currMap[ele] = existingCount * cnt;
                }
                for(auto& [ele, existingCount] : currMap){
                    container.top()[ele] += existingCount;
                }
            } else {
                string current = "";
                current += formula[i];
                i++;
                while(i < n && islower(formula[i])){
                    current += formula[i];
                    i++;
                }

                string count = "";
                while(i < n && isdigit(formula[i])){
                    count += formula[i];
                    i++;
                }
                int cnt = count == "" ? 1 : stoi(count);
                container.top()[current] += cnt;
            }
        }
        string res = "";
        map<string, int> result = container.top();
        container.pop();
        for(auto ele : result){
            res += ele.first;
            if(ele.second > 1){
                res += to_string(ele.second);
            }
        }
        return res;
    }
};