class Solution {
private:
    pair<int,int> getCoordinate(int position, int n){
        int row = (position-1)/n;
        int col = (position-1)%n;
        if(row % 2 != 0){
            col = n - 1 - col;
        }
        row = n - 1 - row;
        return {row, col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        q.push({0, 1});
        vector<bool> visited(n*m+1, false);
        visited[0] = true;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();


            int steps = curr.first;
            int pos = curr.second;
            for(int next = pos + 1; next <= min(pos + 6, n*n);next++){
                auto coordinate = getCoordinate(next, n);
                int x = coordinate.first;
                int y = coordinate.second;

                int newPos = next;
                if(board[x][y] != -1){
                    newPos = board[x][y];
                }

                if(newPos == n*n){
                    return steps + 1;
                }

                if(!visited[newPos]){
                    visited[newPos] = true;
                    q.push({steps + 1, newPos});
                }
            }
        }
        return -1;
    }
};