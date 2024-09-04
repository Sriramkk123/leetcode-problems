class Solution {
private:
    char getNextRight(char currentDirection){
        if(currentDirection == 'N'){
            return 'E';
        }

        if(currentDirection == 'E'){
            return 'S';
        }

        if(currentDirection == 'S'){
            return 'W';
        }

        return 'N';
    }

    char getNextLeft(char currentDirection){
        if(currentDirection == 'N'){
            return 'W';
        }

        if(currentDirection == 'W'){
            return 'S';
        }

        if(currentDirection == 'S'){
            return 'E';
        }

        return 'N';
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstacleSet;
        for(auto obst : obstacles){
            obstacleSet.insert(make_pair(obst[0], obst[1]));
        }
        char direction = 'N';
        pair<int,int> pos = {0,0};
        int res = 0;
        for(auto command : commands){
            if(command < 0){
                if(command == -1){
                    direction = getNextRight(direction);
                }

                if(command == -2){
                    direction = getNextLeft(direction);
                }
                continue;
            }
            int currentX = pos.first;
            int currentY = pos.second;
            bool obstructed = false;
            if(direction == 'N'){
                for(int i = currentY+1;i <= currentY + command;i++){
                    if(obstacleSet.find(pair<int,int>{currentX, i}) != obstacleSet.end()){
                        pos = {currentX, i - 1};
                        obstructed = true;
                        break;
                    } else {
                        continue;
                    }
                }
                if(!obstructed){
                    pos = {currentX, currentY + command};
                }
                res = max(res, (pos.first * pos.first) + (pos.second * pos.second));
                continue;
            }
            if(direction == 'S'){
                for(int i = currentY - 1;i >= currentY - command;i--){
                    if(obstacleSet.find(pair<int,int>{currentX, i}) != obstacleSet.end()){
                        pos = {currentX, i + 1};
                        obstructed = true;
                        break;
                    } else {
                        continue;
                    }
                }
                if(!obstructed){
                    pos = {currentX, currentY - command};
                }
                res = max(res, (pos.first * pos.first) + (pos.second * pos.second));
                continue;
            }
            if(direction == 'E'){
                for(int i = currentX + 1;i <= currentX + command;i++){
                    if(obstacleSet.find(pair<int,int>{i, currentY}) != obstacleSet.end()){
                        pos = {i - 1, currentY};
                        obstructed = true;
                        break;
                    } else {
                        continue;
                    }
                }
                if(!obstructed){
                    pos = {currentX + command, currentY};
                }
                res = max(res, (pos.first * pos.first) + (pos.second * pos.second));
                continue;
            }
            if(direction == 'W'){
                for(int i = currentX - 1;i >= currentX - command;i--){
                    if(obstacleSet.find(pair<int,int>{i, currentY}) != obstacleSet.end()){
                        pos = {i + 1, currentY};
                        obstructed = true;
                        break;
                    } else {
                        continue;
                    }
                }
                if(!obstructed){
                    pos = {currentX - command, currentY};
                }
                res = max(res, (pos.first * pos.first) + (pos.second * pos.second));
                continue;
            }
        }
        return res;
    }
};