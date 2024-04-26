class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        for(int i = 1;i < grid.size();i++){
            auto prev_row = grid[i-1];
            sort(prev_row.begin(), prev_row.end());
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i-1][j] == prev_row[0]){
                    grid[i][j] += prev_row[1];
                } else {
                    grid[i][j] += prev_row[0];
                }
            }
        }
        return *min_element(grid[grid.size() - 1].begin(), grid[grid.size() - 1].end());
    }
};