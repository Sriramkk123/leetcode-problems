class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 1){
            return 1;
        }
        sort(points.begin(), points.end(), [](const vector<int>& l, const vector<int>& r) {
            if (l[1] == r[1])
                return l[0] < r[0];
            return l[1] < r[1];
        });
        int minArrows = 1;
        int end = points[0][1];
        for(int i = 1;i < points.size();i++){
            if(points[i][0] > end){
                minArrows++;
                end = points[i][1];
            }
        }
        return minArrows;
    }
};

// 1 6 | 2 8 | 7 12 | 10 16 |  