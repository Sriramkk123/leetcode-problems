class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
            }
            boats++;
            j--;
        }
        return boats;
    }
};

// 5 1 4 2 
// 1 2 4 5

// 1 2 2 3

// 3 5 3 4
// 3 3 4 5