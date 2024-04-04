class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxCount = 0;
        for(auto ele : s){
            if(ele == '('){
                count++;
            }
            maxCount = max(count, maxCount);
            if(ele == ')'){
                count--;
            }
        }
        return maxCount;
    }
};