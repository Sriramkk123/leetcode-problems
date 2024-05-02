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
class BSTIterator {
private:
    void inorder(TreeNode* root){
        if(!root){
            return;
        }

        inorder(root->left);
        inorders.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorders;
    int currentIdx = 0;
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return inorders[currentIdx++];
    }
    
    bool hasNext() {
        return currentIdx < inorders.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */