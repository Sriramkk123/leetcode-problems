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
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        vector<TreeNode*> res;
        preOrder(root, res);
        for(int i = 1;i < res.size();i++){
            res[i-1]->right = res[i];
            res[i-1]->left = NULL;
        }
        res[res.size() - 1]->right = NULL;
        res[res.size() - 1]->left = NULL;
        return;
    }
    void preOrder(TreeNode* root, vector<TreeNode*>& res){
        if(!root){
            return;
        }

        res.push_back(root);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
};