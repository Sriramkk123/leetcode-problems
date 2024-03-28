class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxRes = INT_MIN;
        int i = 0;
        int j = height.size() - 1;
        while(i < j){
            int currentArea = (j-i) * min(height[i], height[j]);
            maxRes = max(maxRes, currentArea);
            if(height[i] > height[j]){
                j--;
            } else {
                i++;
            }
        }
        return maxRes;
    }
};