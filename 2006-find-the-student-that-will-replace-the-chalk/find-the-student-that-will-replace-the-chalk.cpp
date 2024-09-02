class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        int noOfCompleteCyclesPossible = (k/sum);
        k -= noOfCompleteCyclesPossible*sum;

        int index = 0;
        while(index < chalk.size()){
            if(k >= chalk[index]){
                k -= chalk[index];
                index = index == chalk.size() - 1 ? 0 : index + 1;
            } else {
                return index;
            }
        }
        return -1;
    }
};