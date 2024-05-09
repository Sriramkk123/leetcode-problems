class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        priority_queue<int> pq;
        for(auto ele : happiness){
            pq.push(ele);
        }

        int loss = 0;
        int numChildrenConsidered = 0;
        while(!pq.empty() && numChildrenConsidered < k){
            auto happinessValue = pq.top();
            pq.pop();

            res += max(0, happinessValue - loss);
            numChildrenConsidered++;
            loss += 1;
        }
        return res;
    }
};