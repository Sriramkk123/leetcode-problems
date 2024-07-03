class Solution {
private:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<bool> prev(sum + 1, false);
        vector<bool> curr(sum + 1, false);
        for(int i = 0;i < arr.size();i++){
            prev[0] = true;
        }
        curr[0] = true;
        if(sum >= arr[0]){
            prev[arr[0]] = true;
        }
        for(int i = 1;i < arr.size();i++){
            for(int k = 1;k <= sum;k++){
                bool notTake = prev[k];
                bool take = false;
                if(k >= arr[i]){
                    take = prev[k - arr[i]];
                }
                curr[k] = (take || notTake);   
            }
            prev = curr;
        }
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1){
            return false;
        }

        return isSubsetSum(nums, (sum/2));
    }
};