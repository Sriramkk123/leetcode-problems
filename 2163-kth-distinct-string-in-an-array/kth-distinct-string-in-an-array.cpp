class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto ele : arr){
            mp[ele]++;
        }

        vector<string> distinct;
        for(auto ele : arr){
            if(mp[ele] == 1){
                distinct.push_back(ele);
            }
        }

        if(k > distinct.size()){
            return "";
        }

        return distinct[k-1];
    }
};