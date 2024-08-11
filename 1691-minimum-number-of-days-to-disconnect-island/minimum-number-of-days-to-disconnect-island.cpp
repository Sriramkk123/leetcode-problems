class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() 
            || visited[row][col] || grid[row][col] != 1){
                return;
            }

        visited[row][col] = true;
        dfs(row, col - 1, grid, visited);
        dfs(row - 1, col, grid, visited);
        dfs(row, col + 1, grid, visited);
        dfs(row + 1, col, grid, visited);
    }
    int noOfIslands(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islands = 0;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(i, j, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = noOfIslands(grid);
        if(islands != 1){
            return 0;
        }

        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int newIslandsCount = noOfIslands(grid);
                    if(newIslandsCount != 1){
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};