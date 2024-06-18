class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        vector<pair<int,int>> proDiff;
        for(int i = 0;i < difficulty.size();i++){
            proDiff.push_back({profit[i], difficulty[i]});
        }
        sort(proDiff.begin(), proDiff.end());
        int i = worker.size() - 1;
        int j = proDiff.size() - 1;
        int profitt = 0;
        while(i >= 0 && j >= 0){
            if(proDiff[j].second > worker[i]){
                j--;
                continue;
            } else {
                while(i >= 0 && worker[i] >= proDiff[j].second){
                    profitt += proDiff[j].first;
                    i--;
                }
                j--;
            }
        }
        return profitt;
    }
};