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
private:
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(first && second){
            if(first->val <= second->val){
                temp->next = first;
                first = first->next;
            } else {
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }

        while(first){
            temp->next = first;
            first = first->next;
            temp = temp->next;
        }

        while(second){
            temp->next = second;
            second = second->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    ListNode* mergeHelper(int start, int end, vector<ListNode*>& lists){
        if(start > end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }        

        int mid = (start + end) / 2;
        ListNode* left = mergeHelper(start, mid, lists);
        ListNode* right = mergeHelper(mid+1, end, lists);
        return merge(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        return mergeHelper(0, lists.size() - 1, lists);
    }
};