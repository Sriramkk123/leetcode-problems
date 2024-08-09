class Solution {
private: 
    bool isValidDiagonalSum(int row, int col, vector<vector<int>>& grid){
        int rowSum = INT_MIN;
        int colSum = INT_MIN;
        int diagonalSum1 = INT_MIN;
        int diagonalSum2 = INT_MIN;
        
        unordered_set<int> nums;

        for(int i = row;i < row + 3;i++){
            int localRowSum = 0;
            for(int j = col;j < col + 3;j++){
                if(nums.find(grid[i][j]) != nums.end() || grid[i][j] > 9 || grid[i][j] < 1){
                    return false;
                } else {
                    nums.insert(grid[i][j]);
                }
                localRowSum += grid[i][j];
            }
            if(rowSum == INT_MIN || rowSum == localRowSum){
                rowSum = localRowSum;
                continue;
            } else {
                return false;
            }
        }

        for(int j = col;j < col + 3;j++){
            int localColSum = 0;
            for(int i = row;i < row + 3;i++){
                localColSum += grid[i][j];
            }
            if(colSum == INT_MIN || colSum == localColSum){
                colSum = localColSum;
                continue;
            } else {
                return false;
            }
        }

        int colNum = col;
        for(int i = row;i < row + 3;i++){
            diagonalSum1 += grid[i][colNum++];
        }

        int rowNum = row;
        for(int i = col + 2;i >= col;i--){
            diagonalSum2 += grid[rowNum++][i];
        }

        return diagonalSum1 == diagonalSum2;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m - 2;i++){
            for(int j = 0;j < n - 2;j++){
                if(isValidDiagonalSum(i, j, grid)){
                    res++;
                }
            }
        }
        return res;
    }
};
/*
3 2 9 2 7
6 1 8 4 2
7 5 3 2 7
2 9 4 9 6
4 3 8 2 5
*/