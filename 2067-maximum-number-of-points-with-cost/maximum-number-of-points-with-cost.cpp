class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> previousRow(n, 0);
        for(int i = 0;i < n;i++){
            previousRow[i] = points[0][i];
        }

        for(int i = 0;i < m - 1;i++){
            vector<long long> leftMax(n, 0);
            vector<long long> rightMax(n, 0);
            vector<long long> currentRow(n, 0);

            leftMax[0] = previousRow[0];
            for(int j = 1;j < n;j++){
                leftMax[j] = max(leftMax[j-1] - 1, previousRow[j]); 
            }

            rightMax[n-1] = previousRow[n-1];
            for(int j = n - 2;j >= 0;j--){
                rightMax[j] = max(rightMax[j+1] - 1, previousRow[j]); 
            }

            for(int j = 0;j < n;j++){
                currentRow[j] = points[i + 1][j] + max(leftMax[j], rightMax[j]);
            }

            previousRow = currentRow;
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, previousRow[i]);
        }

        return res;
    }
};