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
    pair<int,int> helper(TreeNode* root, int& moves){
        if(!root){
            return {0,0};
        }

        auto left = helper(root->left, moves);
        auto right = helper(root->right, moves);

        int total_size = left.first + right.first + 1;
        int coins = root->val + left.second + right.second;

        moves += abs(total_size - coins);

        return {total_size, coins};
    }
};