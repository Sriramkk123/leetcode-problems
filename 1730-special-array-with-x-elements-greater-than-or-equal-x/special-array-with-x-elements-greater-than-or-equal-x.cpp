class Solution {
private:
    int findCountGreaterThanEqualTo(int x, map<int, int>& mpp){
        int count = 0;
        for(auto ele : mpp){
            if(ele.first >= x){
                count += ele.second;
            }
        }
        return count;
    }
public:
    int specialArray(vector<int>& nums) {
        map<int, int> mpp;
        int maxElement = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            mpp[nums[i]]++;
            maxElement = max(maxElement, nums[i]);
        }

        for(int i = 0;i <= maxElement;i++){
            int x = i;
            int result = findCountGreaterThanEqualTo(x, mpp);
            if(result == x){
                return x;
            }
        }
        return -1;
    }
};