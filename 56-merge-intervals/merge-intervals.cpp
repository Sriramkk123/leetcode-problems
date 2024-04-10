class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();i++){
            vector<int> previousInterval = res.back();
            vector<int> currentInterval = intervals[i];
            if(previousInterval[1] >= currentInterval[0]){
                int end = max(currentInterval[1], previousInterval[1]);
                res.back()[1] = end;
            } else {    
                res.push_back(currentInterval);
            }
        }
        return res;
    }
};