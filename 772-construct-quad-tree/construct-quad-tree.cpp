/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool isSame(int r, int c, vector<vector<int>>& grid, int n){
        for(int i = r;i < r + n;i++){
            for(int j = c;j < c + n;j++){
                if(grid[i][j] != grid[r][c]){
                    return false;
                }
            }
        }
        return true;
    }
    Node* dfs(int row, int col, vector<vector<int>>& grid, int n){
        if(isSame(row, col, grid, n)){
            Node* node = new Node(grid[row][col], true);
            return node;
        }

        Node* topLeft = dfs(row, col, grid, n/2);
        Node* topRight = dfs(row, col + n/2, grid, n/2);
        Node* bottomLeft = dfs(row + n/2, col, grid, n/2);
        Node* bottomRight = dfs(row + n/2, col + n/2, grid, n/2);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(0, 0, grid, n);
    }
};