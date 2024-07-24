class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> mapper(10);
        for(int i = 0;i < 10;i++){
            mapper[i] = mapping[i];
        }

        vector<int> res;
        vector<pair<int,int>> mp;
        for(int i = 0;i < nums.size();i++){
            int num = nums[i];
            int temp = 0;
            string number = to_string(num);
            for(char digit : number){
                int current = mapper[digit - '0'];
                temp = temp*10 + current;
            }
            mp.push_back({temp, i});
        }
        sort(mp.begin(), mp.end());
        for(auto ele : mp){
            res.push_back(nums[ele.second]);
        }
        return res;
    }
};