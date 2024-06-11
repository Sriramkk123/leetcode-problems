class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> cont;
        for(auto ele : arr1){
            cont[ele]++;
        }

        vector<int> res;
        for(int i = 0;i < arr2.size();i++){
            int curr = arr2[i];
            int countOfCurr = cont[curr];
            cont.erase(curr);
            while(countOfCurr--){
                res.push_back(curr);
            }
        }
        for(auto candidate : cont){
            int element = candidate.first;
            int count = candidate.second;
            while(count--){
                res.push_back(element);
            }
        }
        return res;
    }
};