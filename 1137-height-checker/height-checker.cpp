class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heightsCopy(heights.begin(), heights.end());
        sort(heightsCopy.begin(), heightsCopy.end());
        int res = 0;
        for(int i = 0; i < heights.size();i++){
            res += (heights[i] != heightsCopy[i]);
        }
        return res;
    }
};