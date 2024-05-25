class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int n){
        int rowCopy = row;
        int colCopy = col;

        while(rowCopy >= 0 && colCopy >= 0){
            if(board[rowCopy][colCopy] == 'Q'){
                return false;
            }
            rowCopy--;
            colCopy--;
        }

        rowCopy = row;
        colCopy = col;
        while(colCopy >= 0){
            if(board[rowCopy][colCopy] == 'Q'){
                return false;
            }
            colCopy--;
        }

        rowCopy = row;
        colCopy = col;
        while(rowCopy < n && colCopy >= 0){
            if(board[rowCopy][colCopy] == 'Q'){
                return false;
            }
            colCopy--;
            rowCopy++;
        }
        return true;
    }
    int helper(int col, vector<string>& board, int n){
        if(col == n){
            return 1;
        }

        int res = 0;
        for(int row = 0;row < n;row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                res += helper(col + 1, board, n);
                board[row][col] = '.';
            }
        }

        return res;
    }
public:
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n , '.');
        for(int i = 0;i < n;i++){
            board[i] = s;
        }
        return helper(0, board, n);
    }
};