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
    
    int getParent(int node){
        return parent[node];
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet* aliceDSU = new DisjointSet(n);
        DisjointSet* bobDSU = new DisjointSet(n);
        int aliceEdges = 0;
        int bobEdges = 0;
        int canRemove = 0;
        for(auto edge: edges){
            if(edge[0] == 3){
                if(aliceDSU->findPar(edge[1]) != aliceDSU->findPar(edge[2])){
                    aliceDSU->unionSet(edge[1], edge[2]);
                    bobDSU->unionSet(edge[1], edge[2]);
                    aliceEdges++;
                    bobEdges++;
                } else {
                    canRemove++;
                }
            }
        }
        for(auto edge: edges){
            if(edge[0] == 1){
                if(aliceDSU->findPar(edge[1]) != aliceDSU->findPar(edge[2])){
                    aliceDSU->unionSet(edge[1], edge[2]);
                    aliceEdges++;
                } else {
                    canRemove++;
                }
            } else if(edge[0] == 2){
                if(bobDSU->findPar(edge[1]) != bobDSU->findPar(edge[2])){
                    bobDSU->unionSet(edge[1], edge[2]);
                    bobEdges++;
                } else {
                    canRemove++;
                }
            }
        }
        return aliceEdges == n - 1 && bobEdges == n - 1 ? canRemove : -1;
    }
};