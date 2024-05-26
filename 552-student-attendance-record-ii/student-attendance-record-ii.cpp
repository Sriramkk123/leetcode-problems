class Solution {
private:
    long long recordHelper(int n, int absence, int lateInARow){
        if(n == 0){
            return 1;
        }

        if(dp[n][absence][lateInARow] != -1){
            return dp[n][absence][lateInARow];
        }


        long long res = recordHelper(n - 1, absence, 0);
        if(lateInARow < 2){
            res = res + recordHelper(n - 1, absence, lateInARow + 1);
        }
        if(absence < 1){
            res = res + recordHelper(n - 1, absence + 1, 0);
        }

        return dp[n][absence][lateInARow] = res%mod;
    }
public:
    long long mod = 1e9+7;
    long long dp[100001][2][3];
    int checkRecord(int n) {
        fill(&dp[0][0][0], &dp[0][0][0]+(n+1)*6, -1);
        return recordHelper(n, 0, 0);
    }
};