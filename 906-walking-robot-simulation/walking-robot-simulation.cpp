class Solution {
private:
    char getNextRight(char currentDirection){
        switch (currentDirection) {
            case 'N': return 'E';
            case 'E': return 'S';
            case 'S': return 'W';
            case 'W': return 'N';
        }
        return 'N'; // default case
    }

    char getNextLeft(char currentDirection){
        switch (currentDirection) {
            case 'N': return 'W';
            case 'W': return 'S';
            case 'S': return 'E';
            case 'E': return 'N';
        }
        return 'N'; // default case
    }
    
    bool isObstacle(set<pair<int, int>>& obstacleSet, int x, int y) {
        return obstacleSet.find(make_pair(x, y)) != obstacleSet.end();
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstacleSet;
        for(const auto& obst : obstacles){
            obstacleSet.insert(make_pair(obst[0], obst[1]));
        }
        
        char direction = 'N';
        pair<int,int> pos = {0,0};
        int res = 0;

        for(int command : commands){
            if(command < 0) {
                if(command == -1) {
                    direction = getNextRight(direction);
                } else if(command == -2) {
                    direction = getNextLeft(direction);
                }
                continue;
            }

            int dx = 0, dy = 0;
            if(direction == 'N') dy = 1;
            else if(direction == 'S') dy = -1;
            else if(direction == 'E') dx = 1;
            else if(direction == 'W') dx = -1;

            bool obstructed = false;
            for(int i = 1; i <= command; ++i) {
                int newX = pos.first + i * dx;
                int newY = pos.second + i * dy;
                if(isObstacle(obstacleSet, newX, newY)) {
                    pos = {newX - dx, newY - dy};
                    obstructed = true;
                    break;
                }
            }
            if(!obstructed) {
                pos = {pos.first + command * dx, pos.second + command * dy};
            }
            res = max(res, pos.first * pos.first + pos.second * pos.second);
        }

        return res;
    }
};
