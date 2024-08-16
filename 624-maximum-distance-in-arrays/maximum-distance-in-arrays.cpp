class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0][arrays[0].size() - 1];

        int res = 0;
        for(int i = 1;i < arrays.size();i++){
            vector<int> arr = arrays[i];
            res = max({res, arr[arr.size() - 1] - mini, maxi - arr[0]});
            mini = min(mini, arr[0]);
            maxi = max(maxi, arr[arr.size() - 1]);
        }
        return res;
    }
};