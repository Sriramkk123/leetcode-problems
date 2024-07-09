class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double res = 0;
        long long totalTimeElapsedTillNow = customers[0][0] + customers[0][1];
        long long totalWaitingTime = totalTimeElapsedTillNow - customers[0][0];
        for(int i = 1;i < customers.size();i++){
            int arrivalTime = customers[i][0];
            int prepTime = customers[i][1];
            if(arrivalTime > totalTimeElapsedTillNow){
                totalTimeElapsedTillNow = arrivalTime;
            } 
            totalTimeElapsedTillNow += prepTime;
            totalWaitingTime += (totalTimeElapsedTillNow - arrivalTime);
            
        }
        res =  (double)totalWaitingTime/customers.size();
        return res;
    }
};