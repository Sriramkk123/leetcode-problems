class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map<int,int> takenFruits;
        while(right < fruits.size()){
            takenFruits[fruits[right]]++;
            if(takenFruits.size() > 2){
                if(takenFruits.size() > 2){
                    takenFruits[fruits[left]]--;
                    if(takenFruits[fruits[left]] == 0){
                        takenFruits.erase(fruits[left]);
                    }
                    left++;
                }
            }

            if(takenFruits.size() <= 2){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};