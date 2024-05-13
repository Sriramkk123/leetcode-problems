class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i < n;i++){
            if(grid[i][0] == 0){
                for(int j = 0;j < m;j++){
                    if(grid[i][j] == 0){
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            }
        }

        for(int j = 0;j < m;j++){
            int one_count = 0;
            for(int i = 0;i < n;i++){
                one_count += grid[i][j];
            }
            if(one_count < n - one_count){
                for(int k = 0;k < n;k++){
                    if(grid[k][j] == 0){
                        grid[k][j] = 1;
                    } else {
                        grid[k][j] = 0;
                    }
                }
            }
        }

        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res += grid[i][j]*(1 << m-1-j);
            }
        }
        return res;
    }
};

