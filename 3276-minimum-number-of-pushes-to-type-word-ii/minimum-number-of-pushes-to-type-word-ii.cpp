class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for (auto ch : word) {
            mp[ch]++;
        }

        vector<pair<int, char>> charFreq;
        for (auto ele : mp) {
            charFreq.push_back({ele.second, ele.first});
        }

        sort(charFreq.begin(), charFreq.end(),
             [](auto a, auto b) { return a.first > b.first; });

        int res = 0;
        int countSoFar = 0;
        for (auto ele : charFreq) {
            if (countSoFar < 8) {
                res = res + ele.first;
            } else if (countSoFar < 16) {
                res = res + 2 * ele.first;
            } else if (countSoFar < 24) {
                res = res + 3 * ele.first;
            } else {
                res = res + 4 * ele.first;
            }
            countSoFar++;
        }
        return res;
    }
};