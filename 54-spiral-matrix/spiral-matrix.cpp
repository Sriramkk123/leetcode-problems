class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }

        int startRow = 0;
        int endRow = matrix.size() - 1;
        int startCol = 0;
        int endCol = matrix[0].size() - 1;
        int total = matrix.size() * matrix[0].size();
        int count = 0;

        while (count < total) {
            for (int i = startCol; count < total && i <= endCol; i++) {
                res.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            for (int i = startRow; count < total && i <= endRow; i++) {
                res.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for (int i = endCol; count < total && i >= startCol; i--) {
                res.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for (int i = endRow; count < total && i >= startRow; i--) {
                res.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return res;
    }
};

// 1 2 3 4
// 5 6 7 8
// 9 10 11 12