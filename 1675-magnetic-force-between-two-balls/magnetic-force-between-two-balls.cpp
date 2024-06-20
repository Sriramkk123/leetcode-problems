class Solution {
private:
    int totalBallsPlaced(int force, vector<int>& position, int m){
        int left = 0;
        int right = 1;
        int ballsPlaced = 0;
        while(right < position.size()){
            if(abs(position[right] - position[left]) < force){
                right++;
            } else {
                if(left == 0){
                    ballsPlaced += 2;
                } else {
                    ballsPlaced++;
                }
                left = right;
                right++;
            }
        }
        return ballsPlaced;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 0;
        int high = position[position.size() - 1] - position[0];
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int ballsPlaced = totalBallsPlaced(mid, position, m);
            if(ballsPlaced >= m){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

// 1 2 3 4 5 1000000000
// 1 2 3 4 7
// 22 57 74 79