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
    bool evaluateTree(TreeNode* root) {
        if(!root){
            return false;
        }

        return helper(root);
    }

    bool helper(TreeNode* root){
        if(!root){
            return true;
        }

        bool left = helper(root->left);
        bool right = helper(root->right);

        if(!root->left || !root->right){
            return root->val;
        }

        if(root->left && root->right){
            int rootVal = root->val;
            if(rootVal == 2){
                return left || right;
            } else if(rootVal == 3){
                return left && right;
            }
        }
        return false;
    }
};