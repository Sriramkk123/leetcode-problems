class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxWater(height.size(),0);
        int leftMax = 0;
        for(int i = 0;i < height.size();i++){
            int currentHeight = height[i];
            maxWater[i] = leftMax;   
            leftMax = max(leftMax, currentHeight);
        }

        int rightMax = 0;
        for(int i = height.size() - 1;i >= 0;i--){
            int currentHeight = height[i];
            int minHeight = min(maxWater[i], rightMax);
            if(currentHeight < minHeight){
                maxWater[i] = minHeight - currentHeight;
            }else {
                maxWater[i] = 0;
            }
            rightMax = max(rightMax,currentHeight);
        }
        return accumulate(maxWater.begin(), maxWater.end(),0);
    }
};