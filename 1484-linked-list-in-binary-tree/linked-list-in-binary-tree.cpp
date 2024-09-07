/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPathHelper(TreeNode* root, ListNode* head){
        if(head == NULL){
            return true;
        }

        if(!root){
            return false;
        }

        if(head->val == root->val){
            head = head->next;

            if(isSubPathHelper(root->left, head)){
                return true;
            }

            if(isSubPathHelper(root->right, head)){
                return true;
            }
        }

        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root){
            return false;
        }
        ListNode* tempHead = head;
        return isSubPathHelper(root, tempHead) || isSubPath(tempHead, root->left) || 
            isSubPath(tempHead, root->right);
    }
};