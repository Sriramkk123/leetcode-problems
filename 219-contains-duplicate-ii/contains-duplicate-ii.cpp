class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> cont;
        if(k <= 0){
            false;
        }

        for(int i = 0;i < nums.size();i++){
            if(i > k){
                cont.erase(nums[i-k-1]);
            }
            if(cont.find(nums[i]) != cont.end()){
                return true;
            }
            cont.insert(nums[i]);
        }
        return false;
    }
};