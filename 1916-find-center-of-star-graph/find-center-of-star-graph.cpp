class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> array(1e5+1, 0);
        int maxValue = INT_MIN;
        for(auto edge : edges){
            array[edge[0]]++;
            array[edge[1]]++;
            maxValue = max(maxValue, edge[0]);
            maxValue = max(maxValue, edge[1]);
        }
        for(int i = 0;i <= maxValue;i++){
            if(array[i] == edges.size()){
                return i;
            }
        }
        return -1;
    }
};