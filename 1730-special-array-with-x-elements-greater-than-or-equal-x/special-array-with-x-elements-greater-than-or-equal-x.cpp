class Solution {
private:
    int findCountGreaterThanEqualTo(int x, vector<int>& mpp){
        int count = 0;
        for(int i = x;i < mpp.size();i++){
            count += mpp[i];
        }
        return count;
    }
public:
    int specialArray(vector<int>& nums) {
        vector<int> mpp(1001, 0);
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