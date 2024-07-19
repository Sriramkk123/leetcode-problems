class Solution {
private:
    bool isLucky(int number, int row, int col, vector<vector<int>>& matrix){
        for(int i = 0;i < matrix.size();i++){
            if(matrix[i][col] > number){
                return false;
            }
        }
        
        for(int i = 0;i < matrix[0].size();i++){
            if(matrix[row][i] < number){
                return false;
            }
        }
        
        return true;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int element = matrix[i][j];
                if(isLucky(element, i, j, matrix)){
                    res.push_back(element);
                }
            }
        }
        return res;
    }
};
/*
3  7  8
9  11 13
15 16 17
*/