class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 0;i < n;i++){
            q.push(i);
        }
        int count = k;
        while(q.size() > 1){
            count--;
            while(count-- > 0){
                int val = q.front();
                q.pop();
                q.push(val);
            }
            count = k;
            q.pop();
        }
        return q.front() + 1;
    }
};