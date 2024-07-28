class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n+1];
        for(auto edge : edges){
            int from = edge[0];
            int to = edge[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        queue<int> q;
        q.push(1);
        int currTime = 0;
        int res = -1;
        unordered_map<int, pair<int,int>> visited;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                int curr = q.front();
                q.pop();
                if(curr == n){
                    if(res != -1){
                        return currTime;
                    } 
                    res = currTime;
                }

                for(auto nei : adj[curr]){
                    if(visited.find(nei) == visited.end()){
                        visited[nei] = {1, currTime};
                        q.push(nei);
                    } else {
                            auto currVis = visited[nei];
                            if(currVis.first == 1 && currVis.second != currTime){
                                visited[nei] = {2, currTime};
                                q.push(nei);
                        }
                    }
                }
            }
            if((currTime/change)&1){
                currTime += (change - currTime%change);
            }
            currTime += time;
        }
        return -1; 
    }
};