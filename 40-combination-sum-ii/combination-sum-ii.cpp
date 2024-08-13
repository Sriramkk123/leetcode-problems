class Solution {
private:
    void combinationSum2Helper(int index, vector<int>& candidates, int target, 
                               vector<int>& curr, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(curr);
            return;
        }          

        for(int i = index;i < candidates.size();i++){
            if(i == index || (candidates[i - 1] != candidates[i])){
                if(candidates[i] > target){
                    break;
                }

                curr.push_back(candidates[i]);
                combinationSum2Helper(i + 1, candidates, target - candidates[i], curr, res);
                curr.pop_back();
            }
        }              
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(0, candidates, target, curr, res);
        return res;
    }
};
// 1 1 2 5 6 7 10