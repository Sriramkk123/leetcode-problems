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
    TreeNode* bstHelper(int start, int end, vector<int>& nums){
        if(start > end){
            return NULL;
        }

        int mid = start+(end - start)/2;
        int current = nums[mid];
        TreeNode* root = new TreeNode(current);
        root->left = bstHelper(start, mid - 1, nums);
        root->right = bstHelper(mid + 1, end, nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }

        return bstHelper(0, nums.size() - 1, nums);
    }
};
/*

    0
    -3
    (0, 2)
    (2, 4)



*/