class Solution {
private:
void helper(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& res){
    if(index == candidates.size()){
        if(target == 0){
            res.push_back(current);
        }
        return;
    }

    if(candidates[index] <= target){
        current.push_back(candidates[index]);
        helper(index, candidates, target - candidates[index], current, res);
        current.pop_back();
    }
    helper(index + 1, candidates, target, current, res);

}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;
        helper(0, candidates, target, current, res);
        return res;
    }
};