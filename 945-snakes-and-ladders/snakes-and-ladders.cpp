class Solution {
public:
    pair<int, int> getCoordinate(int n, int number){
        int row = (number - 1)/n;
        int col = (number - 1)%n;
        if(row%2 != 0){
            col = n - 1 - col;
        }
        return pair<int, int>{row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> myBoard = board;
        for (int i = 0; i < n; i++) {
            for(int j = 0;j < n;j++){
                myBoard[i][j] = board[n-i-1][j];
            }
        }
        vector<int> visited(n*n, false);
        queue<pair<int,int>> q;
        q.push({1, 0});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int pos = curr.first;
            int moves = curr.second;

            for(int i = 1;i <= 6;i++){
                int nextPos = pos + i;
                auto coordinate = getCoordinate(n, nextPos);
                int row = coordinate.first;
                int col = coordinate.second;
                if(myBoard[row][col] != -1){
                    nextPos = myBoard[row][col];
                }
                if(nextPos == n*n){
                    return moves + 1;
                }
                if(!visited[nextPos]){
                    visited[nextPos] = true;
                    q.push({nextPos, moves + 1});
                }
            }
        }
        return -1;
    }
};