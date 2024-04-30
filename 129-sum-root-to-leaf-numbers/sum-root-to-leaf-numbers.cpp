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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        return solve(root,res);
    }

    int solve(TreeNode* root, int result){
        if(root == NULL){
            return 0;
        }

        result = result*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            return result;
        }

        int left  = solve(root->left, result);
        int right = solve(root->right, result);
        return left + right;
    }
};