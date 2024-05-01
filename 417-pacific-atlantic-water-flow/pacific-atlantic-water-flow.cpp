class Solution {
public:
    void bfs(vector<vector<int>>& heights, 
            vector<vector<int>>& visited,
            queue<pair<int,int>> oceanQ
            ){
            
            vector<pair<int,int>> dirs = {{0,1}, {1, 0}, {-1,0}, {0,-1}};
            while(!oceanQ.empty()){
                auto curr = oceanQ.front();
                oceanQ.pop();

                for(auto dir : dirs){
                    int dirX = dir.first;
                    int dirY = dir.second;
                    int nextX = curr.first + dir.first;
                    int nextY = curr.second + dir.second;
                    if(nextX < 0 || nextY < 0 || 
                        nextX >= heights.size() || nextY >= heights[0].size() || 
                        visited[nextX][nextY] || 
                        heights[nextX][nextY] < heights[curr.first][curr.second]
                        ){
                            continue;
                        }

                        visited[nextX][nextY] = 1;
                        oceanQ.push({nextX, nextY});
                }
            }    
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>> pacificQ;
        queue<pair<int,int>> atlanticQ;
        vector<vector<int>> pacificVisited(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlanticVisited(heights.size(), vector<int>(heights[0].size(), 0));
        for(int i = 0;i < heights.size();i++){
            for(int j = 0;j < heights[0].size();j++){
                if(i == 0 || j == 0){
                    pacificVisited[i][j] = 1;
                    pacificQ.push({i, j});
                }
                if(i == n - 1 || j == m - 1){
                    atlanticVisited[i][j] = 1;
                    atlanticQ.push({i, j});
                }
            }
        }
        bfs(heights, pacificVisited, pacificQ);
        bfs(heights, atlanticVisited, atlanticQ);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};