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
    TreeNode* insertAtDepth(TreeNode* root, TreeNode* prev, bool fromLeft, bool fromRight, int val, int depth){
        if(depth == 0){
            TreeNode* newNode = new TreeNode(val);
            if(fromLeft){
                prev->left = newNode;
                newNode->left = root;
            } else {
                prev->right = newNode;
                newNode->right = root;
            }
            return newNode;
        }
        
        if(root == NULL){
            return root;
        }

        root->left = insertAtDepth(root->left, root, true, false, val, depth-1);
        root->right = insertAtDepth(root->right, root, false, true, val, depth - 1);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newHead = new TreeNode(val);
            newHead->left = root;
            return newHead;
        }

        return insertAtDepth(root, NULL, false, false, val, depth-1);   
    }
};