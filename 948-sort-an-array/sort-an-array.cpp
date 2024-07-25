class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        map<int, int> holder;
        for(int i = 0;i < nums.size();i++){
            holder[nums[i]]++;
        }
        vector<int> res;
        for(auto ele : holder){
            int times = ele.second;
            while(times--){
                res.push_back(ele.first);
            }
        }
        return res;
    }
};