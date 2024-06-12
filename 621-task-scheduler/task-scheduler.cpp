class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> cont;
        for(auto task : tasks){
            cont[task]++;
        }
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(auto entry : cont){
            pq.push({entry.second});
        }

        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int curr = pq.top();
                pq.pop();

                int remaining = curr - 1;
                if(remaining > 0){
                    q.push({remaining, time + n});
                }
            }

            if(!q.empty()){
                if(q.front().second == time){
                    int rem = q.front().first;
                    pq.push(rem);
                    q.pop();
                }
            }
        }
        return time;
    }
};