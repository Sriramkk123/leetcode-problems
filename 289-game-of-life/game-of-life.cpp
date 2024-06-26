class Solution {
public:
    int getLiveNeighboursCount(int row, int col, vector<vector<int>>& board) {
        int liveCount = 0;
        vector<int> rowPos = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> colPos = {1, 1, 0, -1, -1, -1, 0, 1};
        for (int i = 0; i < rowPos.size(); i++) {
            int nextRowPos = row + rowPos[i];
            int nextColPos = col + colPos[i];
            if (nextRowPos < board.size() && nextRowPos >= 0 &&
                nextColPos < board[0].size() && nextColPos >= 0) {
                if (board[nextRowPos][nextColPos] == 1 || board[nextRowPos][nextColPos] == 3) {
                    liveCount++;
                }
            }
        }
        return liveCount;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int count = getLiveNeighboursCount(i, j, board);
                if(board[i][j] && (count < 2 || count > 3)){
                    board[i][j] = 3;
                } else if(board[i][j] == 0 && count == 3){
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 2){
                    board[i][j] = 1;
                } else if(board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
    }
};