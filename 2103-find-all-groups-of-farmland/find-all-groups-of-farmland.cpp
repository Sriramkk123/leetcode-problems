class Solution {
public:
    int findMax(int a, int b, int c, int d, int e){
        int max1 = max(a,b);
        int max2 = max(c,d);
        int max3 = max(max1, max2);
        return max(e,max3);
    }
    vector<int> findEnd(vector<vector<int>>& land, int row, int col){
        if(row < 0 || col < 0 || row == land.size() || col == land[row].size() || land[row][col] == 0){
            return vector<int>{-1,-1};
        }

        if(land[row][col] == -1){
            return vector<int>{-1,-1};
        }

        land[row][col] = -1;
        vector<int> top = findEnd(land,row - 1,col);
        vector<int> left = findEnd(land,row,col - 1);
        vector<int> bottom = findEnd(land,row + 1,col);
        vector<int> right = findEnd(land,row,col + 1);
        return vector<int>{
            findMax(row, top[0], left[0], bottom[0], right[0]),
            findMax(col, top[1], left[1], bottom[1], right[1])
        };
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        for(int i = 0;i < land.size();i++){
            for(int j = 0;j < land[0].size();j++){
                if(land[i][j] == 1){
                    vector<int> currentStart = vector<int>{i,j};
                    vector<int> currentEnd = findEnd(land,i,j);
                    if(currentEnd[0] != -1 && currentEnd[1] != -1){
                        currentStart.push_back(currentEnd[0]);
                        currentStart.push_back(currentEnd[1]);
                        res.push_back(currentStart);
                    } else {
                        currentStart.push_back(i);
                        currentStart.push_back(j);
                        res.push_back(currentStart);
                    }
                }
            }
        }
        return res;
    }
};