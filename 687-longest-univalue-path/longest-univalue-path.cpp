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
    int longestUnivaluePathHelper(TreeNode* root, int& longestPath){
        if(!root){
            return 0;
        }

        auto left = longestUnivaluePathHelper(root->left, longestPath);
        auto right = longestUnivaluePathHelper(root->right, longestPath);

        if(!root->left || root->left->val != root->val){
            left = 0;
        }

        if(!root->right || root->right->val != root->val){
            right = 0;
        }

        longestPath = max(longestPath, left + right);
        return 1 + max(left, right);
    }   
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        int longesPath = 0;
        longestUnivaluePathHelper(root, longesPath);
        return longesPath;
    }
};