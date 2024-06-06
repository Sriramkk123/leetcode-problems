class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0){
            return false;
        }
        map<int,int> cont;
        for(auto ele : hand){
            cont[ele]++;
        }
        sort(hand.begin(), hand.end());
        for(int i = 0;i < hand.size();i++){
            if(cont[hand[i]] == 0){
                continue;
            }

            for(int j = 0;j < groupSize;j++){
                int currCard = hand[i] + j;

                if(cont[currCard] == 0){
                    return false;
                }

                cont[currCard]--;
            }
        }
        return true;
    }
};