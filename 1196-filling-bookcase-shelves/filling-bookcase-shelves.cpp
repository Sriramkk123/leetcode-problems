class Solution {
private:
    int minHeightShelvesHelper(int index, vector<vector<int>>& books, int shelfWidth, vector<int>& dp){
        if(index == books.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int availableWidth = shelfWidth;
        int maxHeight = 0;
        int res = INT_MAX;
        for(int j = index;j < books.size();j++){
            auto dimension = books[j];
            int width = dimension[0];
            int height = dimension[1];
            if(availableWidth < width){
                break;
            }
            availableWidth -= width;
            maxHeight = max(height, maxHeight);
            res = min(
                res,
                minHeightShelvesHelper(j + 1, books, shelfWidth, dp) + maxHeight
            );
        }
        return dp[index] = res;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size() + 1, -1);
        return minHeightShelvesHelper(0, books, shelfWidth, dp);
    }
};