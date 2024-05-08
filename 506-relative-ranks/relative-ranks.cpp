class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> rank(score.size(), "");
        int maxi = 0;
        for(auto ele : score){
            maxi = max(maxi, ele);
        }

        vector<int> score_index(maxi+1, 0);
        for(int i = 0;i < score.size();i++){
            score_index[score[i]] = i + 1;
        }

        vector<string> medals{"Gold Medal", "Silver Medal", "Bronze Medal"};
        int place = 1;
        for(int i = maxi; i >= 0;i--){
            if(score_index[i] != 0){
                int to_place = score_index[i] - 1;
                if(place < 4){
                    rank[to_place] = medals[place-1];
                }else {
                    rank[to_place] = to_string(place);
                }
                place++;
            }
        }
        return rank;
    }
};

// 5 4 3 2 1
// 0 1 2 3 4
// G S B 4 5