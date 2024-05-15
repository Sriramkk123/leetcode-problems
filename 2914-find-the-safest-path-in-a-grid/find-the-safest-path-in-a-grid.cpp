class Solution {
public:
    vector<int> dirX{1, 0, -1, 0};
    vector<int> dirY{0, -1, 0, 1};
    void bfs(vector<vector<int>>& distance, vector<vector<int>>& grid){
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j]){
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;
            int dist = distance[x][y];
            for(int i = 0;i < 4;i++){
                int nextX = x + dirX[i];
                int nextY = y + dirY[i];
                if(nextX >= 0 && nextY >= 0 && nextX < n && nextY < n && distance[nextX][nextY] > dist + 1){
                    distance[nextX][nextY] = dist + 1;
                    q.push({nextX, nextY});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]){
            return 0;
        }
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        bfs(distance, grid);  
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({distance[0][0],{0, 0}});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int dist = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if(x == n-1 && y == n-1){
                return dist;
            }

            for(int i = 0;i < 4;i++){
                int nextX = x + dirX[i];
                int nextY = y + dirY[i];
                if(nextX >= 0 && nextY >= 0 && nextX < n && nextY < n && !visited[nextX][nextY]){
                    int minDistance = min(dist, distance[nextX][nextY]);
                    pq.push({minDistance,{nextX, nextY}});
                    visited[nextX][nextY] = true;
                }
            }
        }
        return -1;
    }
};
