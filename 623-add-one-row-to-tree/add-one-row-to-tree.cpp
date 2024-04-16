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
    TreeNode* insertAtDepth(TreeNode* root, int val, int depth){
        if(root == NULL){
            return root;
        }
        
        if(depth == 2){
            TreeNode* newLeftNode = new TreeNode(val);
            TreeNode* newRightNode = new TreeNode(val);
            newLeftNode->left = root->left;
            newRightNode->right = root->right;
            root->left = newLeftNode;
            root->right = newRightNode;
            return root;
        }   

        root->left = insertAtDepth(root->left, val, depth-1);
        root->right = insertAtDepth(root->right, val, depth - 1);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newHead = new TreeNode(val);
            newHead->left = root;
            return newHead;
        }

        return insertAtDepth(root, val, depth);   
    }
};