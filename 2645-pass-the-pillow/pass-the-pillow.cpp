class Solution {
public:
    int passThePillow(int n, int time) {
        if(time < n){
            return time + 1;
        }

        n = n - 1;
        if((time/n) & 1){
            return (n + 1 - (time%n));
        }

        return (time%n) + 1;
    }
};