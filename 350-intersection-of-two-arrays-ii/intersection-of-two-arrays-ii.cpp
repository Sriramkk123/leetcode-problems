class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arrayToProcess;
        vector<int> secondary;
        if(nums1.size() <= nums2.size()){
            arrayToProcess = nums1;
            secondary = nums2;
        } else {
            arrayToProcess = nums2;
            secondary = nums1;
        }
        unordered_map<int,int> num1Cont;
        for(auto ele : arrayToProcess){
            num1Cont[ele]++;
        }
        vector<int> res;
        for(auto cand : secondary){
            if(num1Cont[cand] > 0){
                res.push_back(cand);
                num1Cont[cand]--;
            }
        }
        return res;
    }
};