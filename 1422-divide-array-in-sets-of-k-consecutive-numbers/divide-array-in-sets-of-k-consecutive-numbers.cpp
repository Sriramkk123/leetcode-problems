class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0){
            return false;
        }
        map<int,int> cont;
        for(auto ele : nums){
            cont[ele]++;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();i++){
            if(cont[nums[i]] == 0){
                continue;
            }

            for(int j = 0;j < k;j++){
                int curr = nums[i] + j;

                if(cont[curr] == 0){
                    return false;
                }

                cont[curr]--;
            }
        }
        return true;
    }
};