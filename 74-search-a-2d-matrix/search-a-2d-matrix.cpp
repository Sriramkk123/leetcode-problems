class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;
        int startX = 0;
        int startY = m;
        while(startX >= 0 && startY >= 0 && startX <= n && startY <= m){
            int value = matrix[startX][startY];
            if(value == target){
                return true;
            }
            if(value > target){
                startY--;
            } else {
                startX++;
            }
        }
        return false;
    }
};