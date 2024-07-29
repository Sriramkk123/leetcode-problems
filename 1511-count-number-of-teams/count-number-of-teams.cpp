class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int n = rating.size();
        for(int i = 1;i < n - 1;i++){
            int middle = i;
            int leftSmaller = 0;
            int rightLarger = 0;
            for(int j = 0;j < middle;j++){
                if(rating[j] < rating[middle]){
                    leftSmaller++;
                }
            }
            for(int j = middle + 1;j < n;j++){
                if(rating[j] > rating[middle]){
                    rightLarger++;
                }
            }
            res += (leftSmaller * rightLarger);
            int leftLarger = middle - leftSmaller;
            int rightSmaller = n - 1 - middle - rightLarger;
            res += (leftLarger * rightSmaller);
        }
        return res;
    }
};