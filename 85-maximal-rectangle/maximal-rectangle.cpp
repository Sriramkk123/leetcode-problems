class Solution {
public:
    vector<int> nextSmaller(vector<int> array){
        int n = array.size();
        vector<int> res(n);
        stack<int> s;
        s.push(-1);
        for(int i = n - 1;i >= 0;i--){
            int curr = array[i];
            while(s.top() != -1 && array[s.top()] >= curr){
                s.pop();
            }

            res[i] = s.top();
            s.push(i);
        }
        return res;
    }
    vector<int> prevSmaller(vector<int> array){
        int n = array.size();
        vector<int> res(n);
        stack<int> s;
        s.push(-1);
        for(int i = 0;i < n;i++){
            int curr = array[i];
            while(s.top() != -1 && array[s.top()] >= curr){
                s.pop();
            }

            res[i] = s.top();
            s.push(i);
        }
        return res;
    }
    int largestAreaHistogram(vector<int> heights){
        int n = heights.size();
        int maxArea = INT_MIN;
        vector<int> nextSmall = nextSmaller(heights);
        vector<int> prevSmall = prevSmaller(heights);
        for(int i = 0;i < n;i++){
            int length = heights[i];

            if(nextSmall[i] == -1){
                nextSmall[i] = heights.size();
            }

            int breadth = nextSmall[i] - prevSmall[i] - 1;
            int currentArea = length*breadth;
            maxArea = max(maxArea, currentArea);
        } 
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = INT_MIN;
        vector<int> heights(matrix[0].size());
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            res = max(res,largestAreaHistogram(heights));
        }
        return res;   
    }
};

