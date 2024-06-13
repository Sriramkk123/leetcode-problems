class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        if(seats.size() == 1){
            return abs(seats[0] - students[0]);
        }
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;
        int i = 0;
        int j = 0;
        while(i < seats.size() && j < students.size()){
            moves += abs(seats[i] - students[j]);
            i++;
            j++;
        }
        return moves;
    }
};