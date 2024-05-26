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
    int longestUnivaluePathHelper(TreeNode* root, int parentVal, int& longestPath){
        if(!root){
            return 0;
        }

        int val = root->val;
        auto left = longestUnivaluePathHelper(root->left, val, longestPath);
        auto right = longestUnivaluePathHelper(root->right, val, longestPath);
        longestPath = max(longestPath, left + right);
        return parentVal == val ? 1 + max(left, right) : 0;
    }   
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        int longesPath = 0;
        longestUnivaluePathHelper(root, -1, longesPath);
        return longesPath;
    }
};