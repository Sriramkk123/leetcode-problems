class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int res = 0;
        int maxLeft = values[0];
        for (int i = 1; i < n; i++) {
            res = max(res, maxLeft + values[i] - i);
            maxLeft = max(maxLeft, values[i] + i);
        }
        return res;
    }
};