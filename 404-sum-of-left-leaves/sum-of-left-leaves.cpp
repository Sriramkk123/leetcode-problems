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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, bool>> q;
        q.push({root,false});
        while(!q.empty()){
            auto [curr, isLeft] = q.front();
            q.pop();

            if(curr->left == NULL && curr->right == NULL && isLeft){
                res += curr->val;
            }

            if(curr->left){
                q.push({curr->left,true});
            }

            if(curr->right){
                q.push({curr->right, false});
            }
        }
        return res;
    }
};