class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return vector<int>{0};
        }
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto node : edges){
            graph[node[0]].push_back(node[1]);
            graph[node[1]].push_back(node[0]);
            indegree[node[0]]++;
            indegree[node[1]]++;
        }

        vector<int> res;
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int size = q.size();
            res.clear();
            for(int i = 0;i < size;i++){
                int current = q.front();
                q.pop();

                res.push_back(current);
                for(int i = 0;i < graph[current].size();i++){
                    indegree[graph[current][i]]--;
                    if(indegree[graph[current][i]] == 1){
                        q.push(graph[current][i]);
                    }
                }
            }
        }
        return res;
    }
};

// 0 [3]
// 1 [3]
// 2 [3]
// 3 [4]
// 4 [3]
// 5 [4]

// 3 []
// 4 []

