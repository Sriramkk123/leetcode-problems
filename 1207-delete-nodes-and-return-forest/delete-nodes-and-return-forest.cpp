/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root){
            return {};
        }
        vector<TreeNode*> res;
        unordered_set<int> deletableSet(to_delete.begin(), to_delete.end());
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left);
                if(deletableSet.find(curr->left->val) != deletableSet.end()){
                    curr->left = NULL;
                }
            }

            if(curr->right){
                q.push(curr->right);
                if(deletableSet.find(curr->right->val) != deletableSet.end()){
                    curr->right = NULL;
                }
            }

            if(deletableSet.find(curr->val) != deletableSet.end()){
                if(curr->left){
                    res.push_back(curr->left);
                }

                if(curr->right){
                    res.push_back(curr->right);
                }
            }
        }

        if (deletableSet.find(root->val) == deletableSet.end()) {
            res.push_back(root);
        }
        return res;
    }
};