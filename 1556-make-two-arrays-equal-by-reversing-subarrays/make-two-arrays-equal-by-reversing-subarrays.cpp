class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto ele : arr){
            mp[ele]++;
        }
        for(auto ele : target){
            if(mp.find(ele) == mp.end()){
                return false;
            }
            mp[ele]--;
            if(mp[ele] == 0){
                mp.erase(ele);
            }
        }
        return mp.size() == 0;
    }
};