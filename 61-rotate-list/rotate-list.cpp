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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            length++;
        }

        temp = head;
        if(k >= length){
            k = k%length;
        }

        if(k == 0){
            return head;
        }
        
        int count = 0;
        ListNode* prev = head;
        ListNode* newHead = NULL;
        while(temp->next != NULL){
            if(count == (length-k-1)){
                prev = temp;
                newHead = temp->next;
            }
            temp = temp->next;
            count++;
        }
        prev->next = NULL;
        temp->next = head;
        return newHead;
    }
};