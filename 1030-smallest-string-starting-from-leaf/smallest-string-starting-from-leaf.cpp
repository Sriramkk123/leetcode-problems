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
    string smallestFromLeaf(TreeNode* root) {
        string res;
        string curr;
        findSmallest(root, curr, res);
        return res;
    }

    void findSmallest(TreeNode* root, string curr, string& res){
        if(root == NULL){
            return;
        }
        

        if(root->left == NULL && root->right == NULL){
            curr = char(root->val + 'a') + curr;
            if(res.empty()){
                res = curr;
                return;
            }
            res = min(res,curr);
            return;
        }

        curr = char(root->val + 'a') + curr;
        findSmallest(root->left, curr, res);
        findSmallest(root->right, curr, res);
    }
};