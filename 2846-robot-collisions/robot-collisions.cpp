class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> poss;
        for (int i = 0; i < n; i++) {
            poss.push_back(i);
        }
        stack<int> st;
        auto comp = [&](const int a, const int b) {
            return positions[a] < positions[b];
        };
        sort(poss.begin(), poss.end(), comp);
        for (auto id : poss) {
            if (directions[id] == 'R') {
                st.push(id);
            } else {
                while (!st.empty() && healths[id] > 0) {
                    if (healths[st.top()] > healths[id]) {
                        healths[id] = 0;
                        healths[st.top()] -= 1;
                    } else if (healths[st.top()] < healths[id]) {
                        healths[st.top()] = 0;
                        st.pop();
                        healths[id]--;
                    } else {
                        healths[id] = 0;
                        healths[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < healths.size(); i++) {
            if (healths[i] > 0) {
                res.push_back(healths[i]);
            }
        }
        return res;
    }
};
/*
1 2
*/