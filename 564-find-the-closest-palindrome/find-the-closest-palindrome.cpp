class Solution {
private:
    long toPossibility(long left, bool even) {
        long res = left;
        if (!even) left = left / 10;
        while (left > 0) {
            res = res * 10 + left % 10;
            left /= 10;
        }
        return res;
    }
public:
    string nearestPalindromic(string n) {
        int size = n.size();
        int length = size % 2 == 0 ? size / 2 - 1 : size / 2;
        long firstHalf = stol(n.substr(0, length + 1));

        vector<long> options;
        options.push_back(toPossibility(firstHalf, size % 2 == 0));
        options.push_back(toPossibility(firstHalf + 1, size % 2 == 0));
        options.push_back(toPossibility(firstHalf - 1, size % 2 == 0));
        options.push_back((long)pow(10, size - 1) - 1);
        options.push_back((long)pow(10, size) + 1);

        long diff = LONG_MAX;
        long res = 0;
        long nl = stol(n);
        for (auto cand : options) {
            if (cand == nl) continue;
            if (abs(cand - nl) < diff) {
                diff = abs(cand - nl);
                res = cand;
            } else if (abs(cand - nl) == diff) {
                res = min(res, cand);
            }
        }

        return to_string(res);
    }
};