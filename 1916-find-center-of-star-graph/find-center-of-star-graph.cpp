class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(auto edge : edges){
            mp[edge[0]]++;
            mp[edge[1]]++;
        }
        for(auto edge : mp){
            if(edge.second == edges.size()){
                return edge.first;
            }
        }
        return -1;
    }
};