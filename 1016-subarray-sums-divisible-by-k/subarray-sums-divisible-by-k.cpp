class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int preSum = 0;
        prefix[0] = 1;
        int count = 0;
        for(int i = 0;i < nums.size();i++){
            preSum = preSum + nums[i];
            int rem = preSum%k < 0 ? preSum%k + k : preSum%k;
            count += prefix[rem];
            prefix[rem] += 1;   
            cout<<rem<<" "<<prefix[rem]<<"\n";
        }
        return count;
    }
};