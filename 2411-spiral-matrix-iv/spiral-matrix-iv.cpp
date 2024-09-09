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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        ListNode* temp = head;
        int i = 0, j = 0; 
        int cur_d = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (; temp != nullptr; temp = temp->next) {
            res[i][j] = temp->val;
            int newi = i + dirs[cur_d][0], newj = j + dirs[cur_d][1];

            if (newi < 0 || newj < 0 || newi >= m || newj >= n ||
                res[newi][newj] != -1)
                cur_d = (cur_d + 1) % 4;
            i += dirs[cur_d][0];
            j += dirs[cur_d][1];
        }
        return res;
    }
};