class Solution {
private:
    int numBouquets(int day, vector<int>& bloomDay, int k){
        int count = 0;
        int res = 0;
        for(int i = 0;i < bloomDay.size();i++){
            if(day >= bloomDay[i]){
                count++;
            } else {
                res += (count/k);
                count = 0;
            }
        }
        res += (count/k);
        return res;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m * 1LL * k * 1LL > bloomDay.size()){
            return -1;
        }
        long low = *min_element(bloomDay.begin(), bloomDay.end());
        long high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            long mid = (low+high)/2;
            long bouquetsPossible = numBouquets(mid, bloomDay, k);
            if(bouquetsPossible >= m){
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return low;
    }
};