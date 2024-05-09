class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i = 0;i < happiness.size();i++){
            if(i == k){
                break;
            }
            int happinessValue = happiness[i];
            res += max(0, happinessValue - i);
        }        
        return res;
    }
};