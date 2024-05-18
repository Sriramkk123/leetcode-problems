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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        helper(root, moves);
        return moves;
    }
    int helper(TreeNode* root, int& moves){
        if(!root){
            return 0;
        }

        auto left = helper(root->left, moves);
        auto right = helper(root->right, moves);

        int extra_coins = root->val - 1 + left + right;
        moves += abs(extra_coins);
        return extra_coins;
    }
};