class Solution {
public:
    int maxIn3X3(int row, int col, vector<vector<int>>& grid){
        int maxi = INT_MIN;
        int n = grid.size();
        for(int i = row;i < row + 3;i++){
            for(int j = col;j < col + 3;j++){
                maxi = max(maxi, grid[i][j]);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2,0));
        for(int i = 0;i < n-2;i++){
            for(int j = 0;j < n-2;j++){
                res[i][j] = maxIn3X3(i,j, grid);
            }
        }
        return res;      
    }
};