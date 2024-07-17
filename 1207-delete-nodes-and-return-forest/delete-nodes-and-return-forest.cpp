/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void deleteNodesHelper(TreeNode* root, unordered_set<int>& deletableSet,
                           vector<TreeNode*>& res) {
        if (!root) {
            return;
        }

        if (root->left) {
            if (deletableSet.find(root->left->val) != deletableSet.end()) {
                deleteNodesHelper(root->left, deletableSet, res);
                root->left = NULL;
            } else {
                deleteNodesHelper(root->left, deletableSet, res);
            }
        }

        if (root->right) {
            if (deletableSet.find(root->right->val) != deletableSet.end()) {
                deleteNodesHelper(root->right, deletableSet, res);
                root->right = NULL;
            } else {
                deleteNodesHelper(root->right, deletableSet, res);
            }
        }

        if (deletableSet.find(root->val) != deletableSet.end()) {
            if (root->left) {
                res.push_back(root->left);
            }

            if (root->right) {
                res.push_back(root->right);
            }
            return;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> deletableSet(to_delete.begin(), to_delete.end());
        deleteNodesHelper(root, deletableSet, res);
        if (deletableSet.find(root->val) == deletableSet.end()) {
            res.push_back(root);
        }
        return res;
    }
};