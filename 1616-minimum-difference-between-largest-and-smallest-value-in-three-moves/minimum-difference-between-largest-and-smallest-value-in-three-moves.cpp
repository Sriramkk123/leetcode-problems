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
        int left = 3;
        int right = 4;
        vector<int> newNums(8);
        while(!maxH.empty()){
            newNums[left--] = maxH.top();
            maxH.pop();
            newNums[right++] = minH.top();
            minH.pop();
        }
        return min({
            newNums[newNums.size() - 1] - newNums[3],
            newNums[newNums.size() - 2] - newNums[2],
            newNums[newNums.size() - 3] - newNums[1],
            newNums[newNums.size() - 4] - newNums[0]
        });
    }
};
