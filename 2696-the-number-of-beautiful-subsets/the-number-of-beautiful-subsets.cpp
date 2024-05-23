class Solution {
private:
    bool isBeautiful(vector<int>& current, int num, int k){
        current.push_back(num);
        if(current.size() == 1){
            current.pop_back();
            return true;
        }
        for(int i = 0;i < current.size();i++){
            for(int j = i + 1;j < current.size();j++){
                if(abs(current[j] - current[i]) == k){
                    current.pop_back();
                    return false;
                }
            }
        }
        current.pop_back();
        return true;
    }
    void helper(int index, vector<int>& current, vector<int>& nums, int k, int& count){
        if(index == nums.size()){
            if(current.size() != 0){
                count++;
            }
            return;
        }
        
        if(current.size() == 0 || 
            (current.size() > 0 && isBeautiful(current, nums[index], k))){
            current.push_back(nums[index]);
            helper(index + 1, current, nums, k, count);
            current.pop_back();
        }
        helper(index + 1, current, nums, k, count);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        vector<int> current;
        helper(0, current, nums, k, count);
        return count;
    }
};