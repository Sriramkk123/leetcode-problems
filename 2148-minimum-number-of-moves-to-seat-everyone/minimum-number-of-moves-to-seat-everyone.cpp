class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        if(seats.size() == 1){
            return abs(seats[0] - students[0]);
        }
        int moves = 0;
        int maxSeats = *max_element(seats.begin(), seats.end());
        int maxStudents = *max_element(students.begin(), students.end());
        int maxIndex = max(maxSeats, maxStudents) + 1;
        vector<int> seatsBucket(maxIndex);
        vector<int> studentsBucket(maxIndex);
        for(int i = 0;i < seats.size();i++){
            seatsBucket[seats[i]]++;
            studentsBucket[students[i]]++;
        }
        int i = 0;
        int j = 0;
        while(i < maxIndex && j < maxIndex){
            while(i < maxIndex && seatsBucket[i] == 0){
                i++;
            }

            while(j < maxIndex && studentsBucket[j] == 0){
                j++;
            }

            if(i < maxIndex && j < maxIndex){
                seatsBucket[i]--;
                studentsBucket[j]--;
                moves += abs(i - j);
            }
        }
        return moves;
    }
};