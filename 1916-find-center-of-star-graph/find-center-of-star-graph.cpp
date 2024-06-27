class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(auto edge : edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        for(auto edge : mp){
            if(edge.second.size() == edges.size()){
                return edge.first;
            }
        }
        return -1;
    }
};