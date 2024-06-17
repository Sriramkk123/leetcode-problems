class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
           return a[1] < b[1]; 
        });
        int minIntervals = 0;
        int lastSeen = INT_MIN;
        int i = 0;
        while(i < intervals.size()){
            if(intervals[i][0] >= lastSeen){
                lastSeen = intervals[i][1];
                minIntervals++;
            }
            i++;
        }
        return intervals.size() - minIntervals;
    }
};