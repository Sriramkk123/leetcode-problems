class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        string v1;
        vector<int> res1(500);
        int index = 0;
        while(getline(ss1, v1, '.')){
            res1[index++] = stoi(v1);
        }

        stringstream ss2(version2);
        string v2;
        vector<int> res2(500);
        index = 0;
        while(getline(ss2, v2, '.')){
            res2[index++] = stoi(v2);
        }

        for(int i = 0;i < res1.size();i++){
            if(res1[i] > res2[i]){
                return 1;
            }

            if(res1[i] < res2[i]){
                return -1;
            }
        }

        return 0;
    }
};