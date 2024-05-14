class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto ele : nums){
            pq.push(ele);
        }

        while(--k > 0){
            pq.pop();
        } 

        return pq.top();
    }
};