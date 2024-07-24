class Solution {
private:
    vector<int> findNextSmaller(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> findPrevSmaller(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        for(int i = 0;i < n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }
        vector<int> findNextBigger(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }

            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> findPrevBigger(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        for(int i = 0;i < n;i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller = findNextSmaller(arr);
        vector<int> prevSmaller = findPrevSmaller(arr);
        long long res = 0;
        for(int i = 0;i < n;i++){
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            res = (res + (arr[i] * left * 1LL * right));
        }
        return res;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextBigger = findNextBigger(arr);
        vector<int> prevBigger = findPrevBigger(arr);
        long long res = 0;
        for(int i = 0;i < n;i++){
            long long left = i - prevBigger[i];
            long long right = nextBigger[i] - i;
            res = (res + (arr[i] * left * 1LL * right));
        }
        return res;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long mins = sumSubarrayMins(nums);
        long long maxs = sumSubarrayMaxs(nums);
        return maxs - mins;
    }
};