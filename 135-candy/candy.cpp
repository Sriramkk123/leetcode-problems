class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> rewards(ratings.size(), 1);
        for(int i = 1;i < ratings.size();i++){
            if(ratings[i] > ratings[i-1]){
                rewards[i] = rewards[i-1] + 1;
            }
        }

        int sum = 0;
        for(int i = ratings.size() - 2;i >= 0;i--){
            if(ratings[i] > ratings[i + 1]){
                rewards[i] = max(rewards[i],
                                 rewards[i+1] + 1);
            }
            sum += rewards[i];
        }
        return sum + rewards[rewards.size() - 1];
    }
};