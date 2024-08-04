class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sum = 0;
        int mod = 1e9+7;
        for(int i = 0;i < n;i++){
            pq.push({nums[i], i});
        }

        for(int i = 0;i < right;i++){
            auto curr = pq.top();
            pq.pop();

            int index = curr.second;
            int num = curr.first;

            if(i >= left - 1){
                sum = (sum + num)%mod;
            }

            if(index + 1 < n){
                pq.push({num + nums[index + 1], index + 1});
            }
        }
        return sum;
    }
};