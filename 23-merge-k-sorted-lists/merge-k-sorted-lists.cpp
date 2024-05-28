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
    struct compare {
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto list : lists){
            if(list){
                pq.push(list);
            }
        }

        if(pq.empty()){
            return NULL;
        }

        ListNode* dummy = new ListNode(0);
        auto temp = dummy;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            temp->next = curr;
            temp = temp->next;
            if(curr->next){
                pq.push(curr->next);
            }
        }
        return dummy->next;
    }
};