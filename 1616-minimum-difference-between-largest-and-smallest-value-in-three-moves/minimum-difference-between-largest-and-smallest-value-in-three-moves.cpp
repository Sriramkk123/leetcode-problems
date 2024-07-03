class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4){
            return 0;
        }
        priority_queue<int> maxH;
        priority_queue<int, vector<int>, greater<int>> minH;
        for(auto ele : nums){
            maxH.push(ele);
            minH.push(ele);

            if(maxH.size() > 4){
                maxH.pop();
            }
            if(minH.size() > 4){
                minH.pop();
            }
        }
        int mini = INT_MAX;
        vector<int> minFour;
        vector<int> maxFour;
        while(!maxH.empty()){
            minFour.push_back(maxH.top());
            maxFour.push_back(minH.top());
            maxH.pop();
            minH.pop();
        }
        sort(maxFour.begin(), maxFour.end());
        sort(minFour.begin(), minFour.end());
        for(int i = 0;i < 4;i++){
            mini = min(mini, maxFour[i] - minFour[i]);
        }
        return mini;
    }
};
