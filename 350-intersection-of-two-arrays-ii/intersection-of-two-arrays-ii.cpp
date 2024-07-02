class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> num1Cont;
        unordered_map<int,int> num2Cont;
        for(auto ele : nums1){
            num1Cont[ele]++;
        }
        for(auto ele : nums2){
            num2Cont[ele]++;
        }
        vector<int> res;
        for(auto cand : num1Cont){
            int number = cand.first;
            if(num2Cont.find(number) != num2Cont.end()){
                int totalAppearances = min(cand.second, num2Cont[number]);
                while(totalAppearances--){
                    res.push_back(number);
                }
            }
        }
        return res;
    }
};