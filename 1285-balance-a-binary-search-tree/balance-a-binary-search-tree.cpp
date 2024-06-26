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
    void inorder(TreeNode* root, vector<int>& res){
        if(!root){
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
private: 
    TreeNode* construct(int start, int end, vector<int>& res){
        if(start == end){
            return new TreeNode(res[start]);
        }

        if(start > end){
            return NULL;
        }

        int mid = (start + end)/2;
        TreeNode* newNode = new TreeNode(res[mid]);
        newNode->left = construct(start, mid - 1, res);
        newNode->right = construct(mid + 1, end, res);
        return newNode;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return construct(0, res.size() - 1, res);
    }
};