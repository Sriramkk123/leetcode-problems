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
    int maxPathSum(TreeNode* root) {
        int maxSeen = INT_MIN;
        helper(root, maxSeen);
        return maxSeen;
    }
    int helper(TreeNode* root, int& maxSeen) {
        if(!root){
            return 0;
        }

        int leftRes = max(0, helper(root->left, maxSeen));
        int rightRes = max(0, helper(root->right, maxSeen));

        maxSeen = max(maxSeen, root->val + leftRes + rightRes);

        return root->val + max(leftRes, rightRes);
    }
};