class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<int>> col(9,vector<int>(9,0));
        vector<vector<int>> grid(9,vector<int>(9,0));
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board.size();j++){
                if(board[i][j] != '.'){
                    int current = board[i][j] - '1';
                    int k = 3*(i/3) + j/3;
                    if(row[i][current] || col[j][current] || grid[k][current]){
                        return false;
                    }
                    row[i][current] = col[j][current] = grid[k][current] = 1;
                }
            }
        }
        return true;
    }
};