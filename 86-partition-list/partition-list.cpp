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
    ListNode* partition(ListNode* head, int x) {
        ListNode* newLessHead = new ListNode(INT_MAX);
        ListNode* newGreatHead = new ListNode(INT_MAX);
        ListNode* tempLess = newLessHead;
        ListNode* tempGreater = newGreatHead;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                tempLess->next = temp;
                ListNode* nextt = temp->next;
                temp->next = NULL;
                temp = nextt;
                tempLess = tempLess->next;
            } else {
                tempGreater->next = temp;
                ListNode* nextt = temp->next;
                temp->next = NULL;
                temp = nextt;
                tempGreater = tempGreater->next;
            }
        }
        if(tempLess->val != INT_MAX && tempGreater->val != INT_MAX){
            tempLess->next = newGreatHead->next;
            return newLessHead->next;
        }

        if(tempLess->val != INT_MAX){
            return newLessHead->next;
        }
        return newGreatHead->next;
    }
};