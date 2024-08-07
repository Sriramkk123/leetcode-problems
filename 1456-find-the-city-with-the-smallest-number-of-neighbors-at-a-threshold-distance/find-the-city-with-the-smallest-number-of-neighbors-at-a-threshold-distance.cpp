class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }
        for(int i = 0;i < n;i++){
            dist[i][i] = 0;
        }

        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cityNo = 0;
        int count = n;
        for(int i = 0;i < n;i++){
            int cnt = 0;
            for(int j = 0;j < n;j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= count){
                count = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};