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
    void bstToGstHelper(TreeNode* root, int& runningSum){
        if(!root){
            return;
        }

        bstToGstHelper(root->right, runningSum);
        root->val += runningSum;
        runningSum = root->val;
        bstToGstHelper(root->left, runningSum);
        return;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int runningSum = 0;
        bstToGstHelper(root, runningSum);
        return root;
    }
};