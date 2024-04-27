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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(INT_MAX);
        ListNode* evenHead = new ListNode(INT_MAX);
        ListNode* tempOdd = oddHead;
        ListNode* tempEven = evenHead;
        ListNode* temp = head;
        bool isOdd = true;
        while(temp != NULL){
            if(isOdd){
                tempOdd->next = temp;
                ListNode* nextt = temp->next;
                temp->next = NULL;
                temp = nextt;
                tempOdd = tempOdd->next;
            } else {
                tempEven->next = temp;
                ListNode* nextt = temp->next;
                temp->next = NULL;
                temp = nextt;
                tempEven = tempEven->next;
            }
            isOdd = !isOdd;
        }
        tempOdd->next = evenHead->next;
        return oddHead->next;
    }
};