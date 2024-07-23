class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto ele : nums){
            mp[ele]++;
        }

        vector<pair<int,int>> vp;
        for(auto ele : mp){
            vp.push_back({ele.first, ele.second});
        }

        sort(vp.begin(), vp.end(), [](auto a, auto b){
            if(a.second == b.second){
                return a.first > b.first;
            }

            return a.second < b.second;
        });
        vector<int> res;
        for(auto ele : vp){
            int count = ele.second;
            while(count--){
                res.push_back(ele.first);
            }
        }        
        return res;
    }
};