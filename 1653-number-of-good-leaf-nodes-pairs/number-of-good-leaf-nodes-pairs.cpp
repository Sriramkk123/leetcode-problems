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
    vector<int> countPairsHelper(TreeNode* root, int distance, int& pairs){
        if(!root){
            return vector<int>{};
        }
        
        if(!root->left && !root->right){
            return vector<int>{1};
        }

        vector<int> left = countPairsHelper(root->left, distance, pairs);
        vector<int> right = countPairsHelper(root->right, distance, pairs);

        for(int el1 : left){
            for(int el2 : right){
                if(el1 + el2 <= distance){
                    pairs++;
                }
            }
        }

        left.insert(left.end(), right.begin(), right.end());
        for(int i = 0;i < left.size();i++){
            left[i]++;
        }

        return left;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        countPairsHelper(root, distance, res);
        return res;
    }
};