class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        for(int i = 0;i < points.size();i++){
            auto p1 = points[i];
            unordered_map<double, int> longest;
            for(int j = i + 1;j < points.size();j++){
                auto p2 = points[j];
                if(p2[0] == p1[0]){
                    longest[INT_MAX] += 1; 
                    res = max(res, longest[INT_MAX] + 1);
                } else {
                    double slope = (double)((double)(p2[1] - p1[1])/(double)(p2[0] - p1[0]));
                    longest[slope] += 1; 
                    res = max(res, longest[slope] + 1);
                }
            }
        }
        return res;
    }
};