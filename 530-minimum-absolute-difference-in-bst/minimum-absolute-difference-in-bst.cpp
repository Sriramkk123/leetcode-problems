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
    TreeNode* prev;
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root, diff);
        return diff;
    }
    void inorder(TreeNode* root, int& diff){
        if(!root){
            return;
        }

        inorder(root->left, diff);
        if(prev){
            diff = min(diff, root->val - prev->val);
        }
        prev = root;
        inorder(root->right, diff);
    }
};