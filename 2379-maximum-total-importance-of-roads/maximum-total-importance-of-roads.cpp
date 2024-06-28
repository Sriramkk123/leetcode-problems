class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto road : roads){
            degree[road[1]]++;
            degree[road[0]]++;
        }
        sort(degree.begin(), degree.end());
        int imp = 1;
        long long res = 0;
        for(int i = 0;i < degree.size();i++){
            res = res + (long long)imp*degree[i];
            imp++; 
        }
        return res;
    }
};