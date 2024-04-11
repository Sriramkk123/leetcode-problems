class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool newIntervalInserted = false;
        vector<vector<int>> newIntervals;
        for(vector<int> inter : intervals){
            if(inter[0] >= newInterval[0]){
                if(!newIntervalInserted){
                    newIntervals.push_back(newInterval);
                    newIntervalInserted=true;
                }
            }
            newIntervals.push_back(inter);
        }
        if(!newIntervalInserted){
            newIntervals.push_back(newInterval);
        }
        return merge(newIntervals);
    }
};