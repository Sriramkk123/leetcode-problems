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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* temp = reverse(head);
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        int maxValue = INT_MIN;
        while (temp) {
            if (temp->val >= maxValue) {
                prev->next = temp;
                prev = prev->next;
                maxValue = temp->val;
            }
            temp = temp->next;
        }
        prev->next = NULL;
        return reverse(dummy->next);
    }
};
