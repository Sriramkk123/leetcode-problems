class DisjointSet {
    vector<int> size;
    vector<int> parent;
    public:
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0;i <= n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    
    int findPar(int ele){
        if(parent[ele] == ele){
            return ele;
        }
        
        return parent[ele] = findPar(parent[ele]);
    }
    
    void unionSet(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_set<int> stoneNodes;
        for(auto it : stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;
            ds.unionSet(row, col);
            stoneNodes.insert(row);
            stoneNodes.insert(col);
        }

        int noOfComponents = 0;
        for(auto it : stoneNodes){
            if(ds.findPar(it) == it){
                noOfComponents++;
            }
        }
        return n - noOfComponents;
    }
};