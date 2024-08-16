class Solution {
private:
    int miniMax(vector<vector<int>>& arrays){
        int minimumEle = INT_MAX;
        int minimumEleArrayIndex = -1;

        int maximumEle = INT_MIN;
        int maximumEleArrayIndex = -1;

        for(int i = 0;i < arrays.size();i++){
            vector<int> arr = arrays[i];
            if(arr[0] < minimumEle){
                minimumEle = arr[0];
                minimumEleArrayIndex = i;
            }
        }

        for(int i = 0;i < arrays.size();i++){
            vector<int> arr = arrays[i];
            if(arr[arr.size() - 1] > maximumEle && minimumEleArrayIndex != i){
                maximumEle = arr[arr.size() - 1];
                maximumEleArrayIndex = i;
            }
        }

        return (maximumEle - minimumEle);
    }
    
    int maxMini(vector<vector<int>>& arrays){
        int minimumEle = INT_MAX;
        int minimumEleArrayIndex = -1;

        int maximumEle = INT_MIN;
        int maximumEleArrayIndex = -1;

        for(int i = 0;i < arrays.size();i++){
            vector<int> arr = arrays[i];
            if(arr[arr.size() - 1] > maximumEle){
                maximumEle = arr[arr.size() - 1];
                maximumEleArrayIndex = i;
            }
        }

        for(int i = 0;i < arrays.size();i++){
            vector<int> arr = arrays[i];
            if(arr[0] < minimumEle && maximumEleArrayIndex != i){
                minimumEle = arr[0];
                minimumEleArrayIndex = i;
            }
        }

        return (maximumEle - minimumEle);
    }
public:
    int maxDistance(vector<vector<int>>& arrays) {
        for(auto arr : arrays){
            sort(arr.begin(), arr.end());
        }

        return max(miniMax(arrays), maxMini(arrays));
    }
};