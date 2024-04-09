class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets.size() == 1){
            return tickets[0];
        }
        int totalTime = 0;
        while(tickets[k] > 0){
            for(int i = 0;i < tickets.size();i++){
                if(tickets[i] > 0){
                    tickets[i]--;
                    totalTime++;
                    if(i == k && tickets[i] == 0){
                        break;
                    }
                }
            }
        }
        return totalTime;
    }
};
