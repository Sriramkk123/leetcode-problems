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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()){
            return NULL;
        }
        unordered_map<int,int> cont;
        for(int i = 0;i < inorder.size();i++){
            cont[inorder[i]] = i;
        }

        int index = 0;
        return build(preorder, cont, index, 0, preorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, unordered_map<int,int>& cont, int& index, int start, int end){
        if(start > end){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index++]);

        int mid = cont[root->val];

        root->left = build(preorder, cont, index, start, mid - 1);
        root->right = build(preorder, cont, index, mid + 1, end);
        return root;
    }
};

// 3 9 20 15 7
// 9 3 15 20 7