class Solution {
public:
    void solve(int index, int dots, string s, string currIp, vector<string>& res){
        if(index == s.size() && dots == 4){
            if(!currIp.empty()){
                currIp.pop_back();
            }
            res.push_back(currIp);
            return;
        }

        if(dots > 4){
            return;
        }

        for(int j = index;j < index + 3 && j < s.size();j++){
            string substr = s.substr(index, j - index + 1);
            if((index == j || substr[0] != '0') && stoi(substr) <= 255){
                string newIp = currIp + substr + ".";
                solve(j+1, dots + 1, s, newIp, res);
            }

        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        solve(0, 0, s, "", res);
        return res;
    }
};