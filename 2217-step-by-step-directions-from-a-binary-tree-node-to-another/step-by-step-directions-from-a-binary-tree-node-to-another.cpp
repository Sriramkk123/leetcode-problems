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
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root) {
            return root;
        }

        if (root->val == p || root->val == q) {
            return root;
        }

        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        if (left && right) {
            return root;
        }

        if (left) {
            return left;
        }

        return right;
    }
    void findPath(TreeNode* root, string& pathToStart, string& pathToDest, string& curr, int& start, int& dest) {
        if (!root) {
            return;
        }
        if (root->val == start) {
            pathToStart = curr;
        }

        if (root->val == dest) {
            pathToDest = curr;
        }

        curr.push_back('L');
        findPath(root->left, pathToStart, pathToDest, curr, start, dest);
        curr.pop_back();

        curr.push_back('R');
        findPath(root->right, pathToStart, pathToDest, curr, start, dest);
        curr.pop_back();
        return;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lowestCommonAncestor(root, startValue, destValue);
        string pathToStart = "";
        string pathToDest = "";
        string curr = "";
        findPath(lca, pathToStart, pathToDest, curr, startValue, destValue);
        if (pathToStart == "") {
            return pathToDest;
        }
        for (auto& ch : pathToStart) {
            ch = 'U';
        }
        return pathToStart + pathToDest;
    }
};