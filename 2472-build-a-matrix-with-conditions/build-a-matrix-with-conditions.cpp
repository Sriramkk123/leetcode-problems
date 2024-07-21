class Solution {
private:
    vector<int> topoSort(vector<int> adj[], vector<int>& indegree, int k){
        queue<int> q;
        for(int i = 1;i <= k;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            res.push_back(curr);
            for(auto nei : adj[curr]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }   
            }
        }
        return res;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> indegreeRow(k+1, 0);
        vector<int> indegreeCol(k+1, 0);
        vector<int> adjRow[k+1];
        vector<int> adjCol[k+1];
        
        for(auto cand : rowConditions){
            indegreeRow[cand[1]]++;
            adjRow[cand[0]].push_back(cand[1]);
        }

        for(auto cand : colConditions){
            indegreeCol[cand[1]]++;
            adjCol[cand[0]].push_back(cand[1]);
        }

        vector<int> rowTopo = topoSort(adjRow, indegreeRow, k);
        vector<int> colTopo = topoSort(adjCol, indegreeCol, k);
        
        if(rowTopo.size() != k || colTopo.size() != k){
            return vector<vector<int>>{};
        }

        unordered_map<int,int> rowPos;
        unordered_map<int,int> colPos;

        for(int i = 0;i < rowTopo.size();i++){
            rowPos[rowTopo[i]] = i;
        }

        for(int i = 0;i < colTopo.size();i++){
            colPos[colTopo[i]] = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        for(int i = 1;i <= k;i++){
            int row = rowPos[i];
            int col = colPos[i];
            res[row][col] = i;
        }
        return res;
    }
};