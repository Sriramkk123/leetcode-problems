class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        for(int i = 0;i < arr.size();i++){
            int a = arr[i];
            for(int j = i + 1;j < arr.size();j++){
                a = a^arr[j];
                if(a == 0){
                    count += j - i;
                }
            }
        }
        return count;      
    }
};