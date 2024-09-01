class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()){
            return vector<vector<int>>{};
        }
        vector<vector<int>> res(m, vector<int>(n));
        int row = 0;
        int col = 0;
        for(int i = 0;i < original.size();i++){
            if(col == n){
                row++;
                col = 0;
            }
            res[row][col] = original[i];
            col++;
        }
        return res;
    }
};