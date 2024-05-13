class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = n*(1 << (m-1));
        for(int j = 1;j < m;j++){
            int count = 0;
            for(int i = 0;i < n;i++){
                if(grid[i][0] != grid[i][j]){
                    count++;
                }
            }
            int maxi = max(count, n - count);
            res += maxi*(1 << (m - j - 1)); 
        }
        return res;
    }
};

