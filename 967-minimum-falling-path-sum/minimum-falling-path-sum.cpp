class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1;i < n;i++){
            for(int j = 0;j < n;j++){
                int top = matrix[i-1][j];
                int leftTop = INT_MAX;
                int rightTop = INT_MAX;
                if(j - 1 >= 0){
                    leftTop = matrix[i-1][j-1];
                }
                if((j + 1) <= (n - 1)){
                    rightTop = matrix[i-1][j+1];
                }
                matrix[i][j] = matrix[i][j] + min(top, min(leftTop, rightTop));
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};