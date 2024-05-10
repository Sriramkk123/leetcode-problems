class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if(arr.size() <= 2){
            return arr;
        }

        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> minHeap;
        for(int i = 0;i < arr.size();i++){
            minHeap.push({(double)arr[i]/arr.back(), {i, arr.size() - 1}});
        }

        while(--k > 0){
            auto curr = minHeap.top();
            minHeap.pop();
            
            int num = curr.second.first;
            int den = curr.second.second;
            den--;
            if(den > num){
                minHeap.push({(double)arr[num]/arr[den], {num, den}});
            }
        }

        pair<int, int> res = minHeap.top().second;
        return vector<int>{arr[res.first], arr[res.second]};
    }
};