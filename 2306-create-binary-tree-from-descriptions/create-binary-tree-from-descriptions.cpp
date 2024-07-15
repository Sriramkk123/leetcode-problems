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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;
        for(auto entry : descriptions){
            int value = entry[0];
            int child = entry[1];
            int isLeft = entry[2];
            TreeNode* node;
            if(mp.find(value) == mp.end()){
                node = new TreeNode(value);
            } else {
                node = mp[value];
            }

            TreeNode* childNode;
            if(mp.find(child) == mp.end()){
                childNode = new TreeNode(child);
            } else {
                childNode = mp[child];
            }

            if(isLeft){
                node->left = childNode;
            } else {
                node->right = childNode;
            }
            mp[value] = node;
            mp[child] = childNode;
            children.insert(child);
        }

        for(auto description : descriptions){
            if(children.find(description[0]) == children.end()){
                return mp[description[0]];
            }
        }
        return NULL;
    }
};