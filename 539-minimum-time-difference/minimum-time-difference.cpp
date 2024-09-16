class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        unordered_map<string, int> timeToMins;
        for(auto ele : timePoints){
            int hours = stoi(ele.substr(0,2));
            int minutes = stoi(ele.substr(3,2));
            if(timeToMins.find(ele) != timeToMins.end()){
                return 0;
            }
            timeToMins[ele] = hours*60 + minutes;
        }
        vector<int> mins;
        for(auto ele : timeToMins){
            mins.push_back(ele.second);
        }
        sort(mins.begin(), mins.end());

        int ans = INT_MAX;
        for (int i = 0; i < mins.size() - 1; i++) {
            ans = min(ans, mins[i + 1] - mins[i]);
        }

        return min(ans, 24 * 60 - mins[mins.size() - 1] + mins[0]);
    }
};