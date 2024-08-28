class Solution {
private:
    bool isCellLand(int x, int y, vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

    bool isSubIsland(int x, int y, vector<vector<int>>& grid1,
                     vector<vector<int>>& grid2,
                     vector<vector<bool>>& visited) {
        int m = grid2.size();
        int n = grid2[0].size();

        int isSubIsland = true;

        queue<pair<int, int>> pendingCells;

        pendingCells.push({x, y});
        visited[x][y] = true;

        vector<vector<int>>  directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!pendingCells.empty()) {
            int currX = pendingCells.front().first;
            int currY = pendingCells.front().second;
            pendingCells.pop();

            if (!isCellLand(currX, currY, grid1)) {
                isSubIsland = false;
            }

            for (auto& direction : directions) {
                int nextX = currX + direction[0];
                int nextY = currY + direction[1];

                if (nextX >= 0 && nextY >= 0 && nextX < m &&
                    nextY < n && !visited[nextX][nextY] &&
                    isCellLand(nextX, nextY, grid2)) {

                    pendingCells.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }

        return isSubIsland;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (!visited[x][y] && isCellLand(x, y, grid2) &&
                    isSubIsland(x, y, grid1, grid2, visited)) {
                    res += 1;
                }
            }
        }

        return res;
    }
};