class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cont;
        for(auto ele : nums){
            cont[ele]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto entry : cont){
            pq.push({entry.second, entry.first});
        }
        vector<int> res;
        while(!pq.empty() && k--){
            auto curr = pq.top();
            pq.pop();

            res.push_back(curr.second);
        }
        return res;
    }
};