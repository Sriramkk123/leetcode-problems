/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void buildGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& leafs){
        if(!root){
            return;
        }

        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            buildGraph(root->left, adj, leafs);
        }

        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            buildGraph(root->right, adj, leafs);
        }

        if(!root->left && !root->right){
            leafs.insert(root);
        }
    }
    void bfs(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& leafs, int& res, int distance){
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        unordered_set<TreeNode*> visited;
        visited.insert(root);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int dist = curr.second;
            if(dist > distance){
                break;
            }
            if(root != node && dist <= distance && leafs.find(node) != leafs.end()){
                res++;
            }

            for(auto nei : adj[node]){
                if(visited.find(nei) == visited.end()){
                    q.push({nei, dist + 1});
                    visited.insert(nei);
                }
            }
        }
    }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leafs;
        buildGraph(root, adj, leafs);
        int res = 0;
        for(auto node : leafs){
            bfs(node, adj, leafs, res, distance);
        }
        return res/2;
    }
};