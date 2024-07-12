class Solution {
private:
    int findMaxGain(string s, int x, int y){
        int res = 0;
        string st;
        
        for (char ch : s) {
            if (!st.empty() && ((x > y && ch == 'b' && st[st.size() - 1] == 'a') || 
                                (y > x && ch == 'a' && st[st.size() - 1] == 'b'))) {
                res += max(x, y);
                st.pop_back();
            } else {
                st.push_back(ch);
            }
        }
        
        if(st.empty()){
            return res;
        }

        string remaining = st;
        st.clear();
        
        for (char ch : remaining) {
            if (!st.empty() && ((x <= y && ch == 'b' && st[st.size() - 1] == 'a') || 
                                (y <= x && ch == 'a' && st[st.size() - 1] == 'b'))) {
                res += min(x, y);
                st.pop_back();
            } else {
                st.push_back(ch);
            }
        }
        
        return res;
    }
public:
    int maximumGain(string s, int x, int y) {
        int res = findMaxGain(s, x, y);
        return res;
    }
};