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
    unordered_map<int, int> countPairsHelper(TreeNode* root, int distance, int& pairs){
        if(!root){
            return unordered_map<int, int>{};
        }
        
        if(!root->left && !root->right){
            unordered_map<int, int> count;
            count[1] = 1;
            return count;
        }

        unordered_map<int, int> left = countPairsHelper(root->left, distance, pairs);
        unordered_map<int, int> right = countPairsHelper(root->right, distance, pairs);

        for(auto el1 : left){
            for(auto el2 : right){
                if(el1.first + el2.first <= distance){
                    pairs += left[el1.first] * right[el2.first];
                }
            }
        }

        unordered_map<int,int> res;
        for(auto ele : left){
            if(ele.first + 1 <= distance){
                res[ele.first + 1] = left[ele.first];
            }
        }

        for(auto ele : right){
            if(ele.first + 1 <= distance){
                res[ele.first + 1] += right[ele.first];
            }
        }
        return res;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        countPairsHelper(root, distance, res);
        return res;
    }
};