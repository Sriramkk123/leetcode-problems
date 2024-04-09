class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets.size() == 1){
            return tickets[0];
        }
        int totalTime = 0;
        for(int i = 0;i < tickets.size();i++){
            if(i <= k){
                totalTime += min(tickets[i], tickets[k]);
            } else {
                totalTime += min(tickets[k] - 1, tickets[i]);
            }
        }
        return totalTime;
    }
};
