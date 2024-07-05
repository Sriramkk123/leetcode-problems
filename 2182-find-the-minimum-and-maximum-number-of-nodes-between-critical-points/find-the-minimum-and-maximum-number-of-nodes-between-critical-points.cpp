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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2,-1);
        vector<int> criticals;
        ListNode* temp = head;
        ListNode* prev = head;
        temp = temp->next;
        int count = 1;
        while(temp){
            int prevValue = prev->val;
            int currentValue = temp->val;
            ListNode* next = temp->next;
            if(!next){
                break;
            }
            int nextValue = next->val;
            if((currentValue > prevValue && currentValue > nextValue) || 
                (currentValue < prevValue && currentValue < nextValue)){
                    criticals.push_back(count);
                }
            count++;
            prev = temp;
            temp = temp->next;
        }
        if(criticals.size() <= 1){
            return res;
        }

        if(criticals.size() == 2){
            res[0] = res[1] = criticals[1] - criticals[0];
        } else {
            res[1] = criticals[criticals.size() - 1] - criticals[0];
            int minGap = INT_MAX;
            for(int i = 0;i < criticals.size() - 1;i++){
                int gap = criticals[i + 1] - criticals[i];
                minGap = min(gap, minGap);
            }
            res[0] = minGap;
        }
        return res;
    }
};