class Solution {
private:
    struct compare {
        bool operator()(vector<int> a, vector<int> b){
            return a[0] + a[1] > b[0] + b[1];
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty() || k == 0){
            return res;
        }
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(int i = 0;i < nums1.size() && i < k;i++){
            pq.push({ nums1[i], nums2[0], 0});
        }

        while(k-- > 0 && !pq.empty()){
            auto curr = pq.top();
            pq.pop();

            res.push_back({curr[0], curr[1]});
            if(curr[2] == nums2.size() - 1){
                continue;
            }
            int nextElementInSecondArray = nums2[curr[2] + 1];
            pq.push({ curr[0], nextElementInSecondArray, curr[2] + 1});
        }
        return res;
    }
};