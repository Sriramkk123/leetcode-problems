class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses, 0);
        for(int i = 0;i < prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }

        queue<int> q;
        for(int i = 0;i < numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> res(numCourses);
        int index = numCourses - 1;
        while(!q.empty()){
            auto curr = q.front();
            res[index--] = (curr);
            q.pop();

            for(auto nei : graph[curr]){
                indegree[nei]--;

                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return index == -1 ? res : vector<int>{};
    }
};