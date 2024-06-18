class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        vector<pair<int,int>> proDiff;
        for(int i = 0;i < difficulty.size();i++){
            proDiff.push_back({profit[i], difficulty[i]});
        }
        priority_queue<pair<int,int>> pq;
        for(auto ele : proDiff){
            pq.push({ele.first, ele.second});
        }
        int i = worker.size() - 1;
        int profitt = 0;
        while(i >= 0 && !pq.empty()){
            auto curr = pq.top();
            pq.pop();

            if(curr.second > worker[i]){
                continue;
            } else {
                while(i >= 0 && worker[i] >= curr.second){
                    profitt += curr.first;
                    i--;
                }
            }
        }
        return profitt;
    }
    // 96, 58
    // 90, 37
    // 4, 13

    // 34, 73, 45
};