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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* headDummy = head->next;
        while(headDummy){
            int sum = 0;
            while(headDummy->val != 0){
                sum += headDummy->val;
                headDummy = headDummy->next;
            }
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = temp->next;
            headDummy = headDummy->next;
        }
        ListNode* toReturn = dummy->next;
        delete(dummy);
        return toReturn;
    }
};