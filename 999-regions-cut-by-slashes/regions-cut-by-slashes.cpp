class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& scaledGrid){
        if(row < 0 || col < 0 || row >= scaledGrid.size() || col >= scaledGrid[0].size() || 
            scaledGrid[row][col] != 0){
                return;
            }

        scaledGrid[row][col] = 1;

        vector<int> dirX = {0, -1, 0, 1};
        vector<int> dirY = {-1, 0, 1, 0};
        for(int i = 0;i < 4;i++){
            dfs(row + dirX[i], col + dirY[i], scaledGrid);
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> scaledGrid(rows*3, vector<int>(cols*3, 0));

        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                int scaledRow = i * 3;
                int scaledCol = j * 3;
                if(grid[i][j] == '/'){
                    scaledGrid[scaledRow][scaledCol+2] = 1;
                    scaledGrid[scaledRow+1][scaledCol+1] = 1;
                    scaledGrid[scaledRow+2][scaledCol] = 1;
                }else if(grid[i][j] == '\\'){
                    scaledGrid[scaledRow][scaledCol] = 1;
                    scaledGrid[scaledRow+1][scaledCol+1] = 1;
                    scaledGrid[scaledRow+2][scaledCol+2] = 1;
                }
            }
        }

        int res = 0;
        for(int i = 0;i < rows*3;i++){
            for(int j = 0;j < cols*3;j++){
                if(scaledGrid[i][j] == 0){
                    dfs(i, j, scaledGrid);
                    res++;
                }
            }
        }
        return res;
    }
};