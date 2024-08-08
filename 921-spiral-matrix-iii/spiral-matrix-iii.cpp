class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int rowStart = rStart;
        int colStart = cStart;
        int i = 0;
        int steps = 1;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(res.size() != rows*cols){
            for(int times = 0;times < 2;times++){
                auto currentCoord = dirs[i];
                int dr = currentCoord[0];
                int dc = currentCoord[1];
                for(int j = 0;j < steps;j++){
                    if(rowStart >= 0 && rowStart < rows && colStart >= 0&& colStart < cols){
                        res.push_back({rowStart, colStart});
                    }
                    rowStart = rowStart + dr;
                    colStart = colStart + dc;
                }
                i = (i + 1)%4;
            }
            steps++;
        }
        return res;
    }
};