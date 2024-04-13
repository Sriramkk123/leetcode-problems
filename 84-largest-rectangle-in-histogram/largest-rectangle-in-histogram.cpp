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
    int largestRectangleArea(vector<int>& heights) {
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
};