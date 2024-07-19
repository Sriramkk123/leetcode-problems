class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowMin(m);
        vector<int> colMax(n);
        for(int i = 0;i < m;i++){
            int mini = INT_MAX;
            for(int j = 0;j < n;j++){
                mini = min(mini, matrix[i][j]);
            }
            rowMin[i] = mini;
        }

        for(int j = 0;j < n;j++){
            int maxi = INT_MIN;
            for(int i = 0;i < m;i++){
                maxi = max(maxi, matrix[i][j]);
            }
            colMax[j] = maxi;
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]){
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};