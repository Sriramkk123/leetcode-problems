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
        solve(root,"",res);
        return res;
    }

    void solve(TreeNode* root, string res, int& result){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            res += to_string(root->val);
            result += stoi(res);
            return;
        }

        solve(root->left, res+to_string(root->val),result);
        solve(root->right, res+to_string(root->val), result);
    }
};