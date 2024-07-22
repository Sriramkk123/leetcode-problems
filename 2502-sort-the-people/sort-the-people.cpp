class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<pair<int, string>> heightsWithNames;
        for(int i = 0;i < n;i++){
            heightsWithNames.push_back({heights[i], names[i]});
        }

        sort(heightsWithNames.begin(), heightsWithNames.end(), greater<pair<int,string>>());

        vector<string> res;
        for(int i = 0;i < n;i++){
            res.push_back(heightsWithNames[i].second);
        }
        return res;
    }
};