class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProfit = 0;
        int maxDifficulty = *max_element(difficulty.begin(), difficulty.end());
        vector<int> difficultyInd(maxDifficulty + 1, 0);
        for(int i = 0;i < difficulty.size();i++){
            difficultyInd[difficulty[i]] = max(difficultyInd[difficulty[i]], profit[i]);
        }
        for(int i = 1;i <= maxDifficulty;i++){
            difficultyInd[i] = max(difficultyInd[i-1], difficultyInd[i]);
        }
        for(int i = 0;i < worker.size();i++){
            if(worker[i] >= maxDifficulty){
                maxProfit += difficultyInd[maxDifficulty];
            } else {
                maxProfit += difficultyInd[worker[i]];
            }
        }
        return maxProfit;
    }
};