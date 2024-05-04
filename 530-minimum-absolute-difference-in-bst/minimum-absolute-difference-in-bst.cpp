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
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        helper(root, inorder);
        sort(inorder.begin(), inorder.end());
        int mini = INT_MAX;
        for(int i = 1;i < inorder.size();i++){
            if(abs(inorder[i] - inorder[i-1]) < mini){
                mini = abs(inorder[i] - inorder[i-1]);
            }
        }
        return mini;
    }
    void helper(TreeNode* root, vector<int>& inorder){
        if(!root){
            return;
        }

        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
    }
};