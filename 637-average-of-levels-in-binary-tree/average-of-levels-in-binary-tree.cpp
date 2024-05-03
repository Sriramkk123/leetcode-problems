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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root){
            return vector<double>{};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while(!q.empty()){
            int size = q.size();
            double parRes = 0;
            for(int i = 0;i < size;i++){
                auto current = q.front();
                q.pop();

                parRes += (double)current->val;
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
            parRes = parRes/size;
            res.push_back(parRes);
        }
        return res;
    }
};