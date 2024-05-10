class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if(arr.size() <= 2){
            return arr;
        }

        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> minHeap;
        for(int i = 0;i < arr.size();i++){
            for(int j = i + 1;j < arr.size();j++){
                minHeap.push({(double)arr[i]/arr[j], {arr[i], arr[j]}});
            }
        }

        pair<int, int> res;
        for(int i = 0;i < k;i++){
            res = minHeap.top().second;
            minHeap.pop();
        }
        return {res.first, res.second};
    }
};