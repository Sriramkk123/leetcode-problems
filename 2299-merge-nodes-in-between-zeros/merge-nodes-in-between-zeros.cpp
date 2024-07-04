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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* headDummy = head->next;
        while(headDummy){
            if(headDummy->val == 0){
                ListNode* newNode = new ListNode(sum);
                temp->next = newNode;
                temp = temp->next;
                sum = 0;
            } else {
                sum += headDummy->val;
            }
            headDummy = headDummy->next;
        }
        return dummy->next;
    }
};