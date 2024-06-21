class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxSatisfaction = 0;
        int currentWindowSatisfaction = 0;
        int initialSatisfaction = 0;
        for(int i = 0;i < customers.size();i++){
            if(grumpy[i] == 0){
                initialSatisfaction += customers[i];
            } else if(i < minutes){
                currentWindowSatisfaction += customers[i];
            }
        }

        maxSatisfaction = currentWindowSatisfaction;
        for(int i = minutes;i < customers.size();i++){
            currentWindowSatisfaction += (customers[i] * grumpy[i]);
            currentWindowSatisfaction -= (customers[i - minutes] * grumpy[i - minutes]);
            maxSatisfaction = max(maxSatisfaction, currentWindowSatisfaction);
        }
        return initialSatisfaction + maxSatisfaction;
    }
};