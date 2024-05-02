class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxEle = INT_MIN;
        unordered_set<int> cont;
        sort(nums.begin(), nums.end(), [](int a, int b){
            return a > b;
        });
        for(auto ele : nums){
            if(ele < 1){
                int positive = -1*ele;
                if(positive > maxEle && cont.find(positive) != cont.end()){
                    maxEle = positive;
                }
            } else {
                cont.insert(ele);
            }
        }
        return maxEle == INT_MIN ? -1 : maxEle;
    }
};