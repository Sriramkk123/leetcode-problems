class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> scoreMap;
        for(int i = 0;i < score.size();i++){
            scoreMap[score[i]] = i; 
        }
        vector<string> res(score.size());

        vector<int> temp(score.begin(), score.end());
        sort(temp.begin(), temp.end(), [](int a, int b){
            return a > b;
        });
        bool goldGiven = false;
        bool silverGiven = false;
        bool bronzeGiven = false;
        int remainPos = 4;
        for(int i = 0; i < temp.size();i++){
            int ele = temp[i];
            if(!goldGiven){
                res[scoreMap[ele]] = "Gold Medal";
                goldGiven = true;
                continue;
            }
            if(goldGiven && !silverGiven){
                res[scoreMap[ele]] = "Silver Medal";
                silverGiven = true;
                continue;
            }
            if(goldGiven && silverGiven && !bronzeGiven){
                res[scoreMap[ele]] = "Bronze Medal";
                bronzeGiven = true;
                continue;
            }
            res[scoreMap[ele]] = to_string(remainPos);
            remainPos++;
        }
        return res;
    }
};

// 5 4 3 2 1
// 0 1 2 3 4
// G S B 4 5