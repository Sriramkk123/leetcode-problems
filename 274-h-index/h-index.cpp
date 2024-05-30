class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for(auto ele : citations){
            if(ele > n){
                count[n]++;
            } else {
                count[ele]++;
            }
        }

        int total = 0;
        for(int i = n;i >= 0;i--){
            total += count[i];
            if(total >= i){
                return i;
            }
        }
        return 0;
    }
};
// 1 1 2 3 4 5 7