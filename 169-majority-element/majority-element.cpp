class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majEle = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            if(count == 0){
                majEle = nums[i];
                count++;
            } else if(nums[i] == majEle){
                count++;
            }else {
                count--;
            }
        }
        return majEle;
    }
};