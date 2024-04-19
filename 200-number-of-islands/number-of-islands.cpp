class Solution {
public:
    void markAllNeighbours(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';
        markAllNeighbours(grid,i+1,j);
        markAllNeighbours(grid,i-1,j);
        markAllNeighbours(grid,i,j+1);
        markAllNeighbours(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == '1'){
                    numOfIslands++;
                    markAllNeighbours(grid,i,j);
                }
            }
        }   
        return numOfIslands;
    }
};