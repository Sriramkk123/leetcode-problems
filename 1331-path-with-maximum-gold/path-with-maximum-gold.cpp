class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] <= 0){
            return 0;
        }

        int goldHere = grid[row][col];
        grid[row][col] = -1;
        int top = dfs(row - 1, col, grid);
        int left = dfs(row, col - 1, grid);
        int bottom = dfs(row + 1, col, grid);
        int right = dfs(row, col + 1, grid);

        grid[row][col] = goldHere;
        int leftRightMax = max(left, right);
        int topBottomMax = max(top, bottom);
        return goldHere + max(leftRightMax, topBottomMax);
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] > 0){
                    maxGold = max(maxGold, dfs(i,j,grid));
                }
            }
        }
        return maxGold;
    }
};