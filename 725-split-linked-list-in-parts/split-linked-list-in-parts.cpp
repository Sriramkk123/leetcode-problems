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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }
        vector<ListNode*> res;
        int parts = length / k;
        int extra = length % k;

        temp = head;
        ListNode* prev = temp;
        for(int i = 0;i < k;i++){
            ListNode* currHead = temp;

            int currentSize = parts;

            if (extra > 0) {
                extra--;
                currentSize++;
            }

            int j = 0;
            while (j < currentSize) {
                prev = temp;
                if (temp != nullptr) {
                    temp = temp->next;
                }
                j++;
            }

            if (prev != nullptr) {
                prev->next = nullptr;
            }

            res.push_back(currHead);
        }
        return res;
    }
};