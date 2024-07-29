class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int n = rating.size();
        for (int i = 0; i < n - 2; i++) {
            int current = rating[i];
            for (int j = i + 1; j < n - 1; j++) {
                int second = rating[j];
                if (current > second) {
                    for (int k = j + 1; k < n; k++) {
                        int third = rating[k];
                        if (second > third) {
                            res++;
                        }
                    }
                } else if (current < second) {
                    for (int k = j + 1; k < n; k++) {
                        int third = rating[k];
                        if (second < third) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};