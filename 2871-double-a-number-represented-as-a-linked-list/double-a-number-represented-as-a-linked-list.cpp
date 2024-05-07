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
    ListNode* reverse(ListNode* root){
        ListNode* temp = root;
        ListNode* prev = NULL;
        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* doubleLL(ListNode* root){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;
        while(root || carry){
            int sum = 0;
            if(root){
                sum += root->val*2;
                root = root->next;
            }

            sum += carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp = temp->next;
        }
        return dummy->next;
    }
    ListNode* doubleIt(ListNode* head) {
        if(!head){
            return head;
        }

        ListNode* reversedHead = reverse(head);
        ListNode* result = doubleLL(reversedHead);
        return reverse(result);
    }
};