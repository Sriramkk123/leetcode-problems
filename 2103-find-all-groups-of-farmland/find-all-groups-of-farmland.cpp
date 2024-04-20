class Solution {
public:
    void findEnd(vector<vector<int>>& land, int row, int col, vector<int>& temp){
        if(row < 0 || col < 0 || row == land.size() || col == land[row].size() || land[row][col] == 0){
            return;
        }

        if(land[row][col] == -1){
            return;
        }

        if(row > temp[2]){
            temp[2] = row;
            temp[3] = col;
        } else if(row == temp[2] && col > temp[3]){
            temp[3] = col;
        }

        land[row][col] = -1;
        findEnd(land,row - 1,col,temp);
        findEnd(land,row,col - 1,temp);
        findEnd(land,row + 1,col,temp);
        findEnd(land,row,col + 1,temp);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        for(int i = 0;i < land.size();i++){
            for(int j = 0;j < land[0].size();j++){
                if(land[i][j] == 1){
                    vector<int> currentLand = vector<int>{i,j,i,j};
                    findEnd(land,i,j,currentLand);
                    res.push_back(currentLand);
                }
            }
        }
        return res;
    }
};